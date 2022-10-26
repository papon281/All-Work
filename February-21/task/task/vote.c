#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

/**
 * This is the main function of this program.
 */


/*
    The following function converts a character array to integer
    I am assuming the character array will contains numeric only
*/
int toInt(char* data){
    int n = strlen(data), i, res = 0;
    for(i = 0; i < n; i++){
        res = res * 10 + (data[i]-'0');
    }
    return res;
}

/*
    The following method extract required data passed from command line
    This function search for two option:
    option -f followed by a filename
    option -m followed by the capacity of the hashtable
*/
void extractCommand(int argc, char* argv[], int* fileNameIndex, int* tableSize){
    int i;
    for(i = 0; i < argc; i++){
        if(strcmp(argv[i],"-f") == 0){
            if(i < argc-1){
                *fileNameIndex = i+1;
            }
        } else if(strcmp(argv[i], "-m") == 0){
            if( i < argc-1){
                *tableSize = toInt(argv[i+1]);
            }
        }
    }
}

/*
    The following method load voters information from a file
*/
void loadFromFile(struct HashTable* table, char* fileName){
    FILE *file = fopen(fileName, "r");
    if(file != NULL){
        int RIN, zip;
        char firstName[50], lastName[50];
        while(fscanf(file, "%d", &RIN) != EOF){
            fscanf(file, "%s %s %d", lastName, firstName, &zip);
            insert(table, RIN, firstName, lastName, zip);
        }
        fclose(file);
    }
}

int main(int argc, char* argv[]) {
    int fileIndex = -1; // if no file information is passed from command line
    int mapSize = 100; // default capacity of hash table
    extractCommand(argc, argv, &fileIndex, &mapSize); // invoke method
    struct HashTable* table = createNewTable(mapSize); // create a hashtable
    if(fileIndex != -1){
        loadFromFile(table, argv[fileIndex]); // invoke method
    }

    char choice[10];

    while (1) {
        scanf("%s", choice); // read user's choice
        if(strcmp(choice, "l") == 0) {
            // choice is lookup
            int residentId;
            scanf("%d", &residentId);
            search(table, residentId);
        } else if(strcmp(choice, "i") == 0) {
            // choice is insert
            int rin, zip;
            char lname[50], fname[50];
            scanf("%d %s %s %d", &rin, lname, fname, &zip);
            insert(table, rin, lname, fname, zip);
        } else if(strcmp(choice, "d") == 0) {
            // choice is delete
            int residentId;
            scanf("%d", &residentId);
            removeFromTable(table, residentId);
        } else if(strcmp(choice, "r") == 0){
            // choice is registration
            int residentId;
            scanf("%d", &residentId);
            if(registeredVoter(table, residentId)) {
                printf("Registration Complted\n");
            } else {
                printf("Already registered or Entry Deleted\n");
            }
        } else if(strcmp(choice, "bv") == 0) {
            // choice is registration from a file
            // I am assuming the file will contain space separated integers
            char fileName[50];
            scanf("%s", fileName);
            bulkRegister(table, fileName);
        } else if(strcmp(choice, "v") == 0){
            // choice is to display the total vote casted
            printf("Cast Vote: %d\n",countTotalVoteCasted(table));
        } else if(strcmp(choice, "perc") == 0){
            // choice is to display the vote cast percentage against total user
            printf("Cast Vote Percentage: %.02f\n",calculatePercentage(table));
        } else if(strcmp(choice, "z") == 0) {
            // choice is to display casted vote count of a zip code region
            int zipCode;
            scanf("%d", &zipCode);
            printParticipantId(table, zipCode);
        } else if(strcmp(choice, "o") == 0) {
            // choice is to display vote cast count against zipcode in descending order
            // I have trucated the zipcode where 0 votes are casted from displaying
            printZipCode(table);
        } else if(strcmp(choice, "exit") == 0) {
            // exit the program
            printf("Exit here\n");
            break;
        } else{
            printf("Enter the right key.\n");
        }
    }
    return 0;
}