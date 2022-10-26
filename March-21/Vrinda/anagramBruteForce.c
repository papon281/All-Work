#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
int count =0;

int check_anagram(char* str, char* word){

    int charCountFirst[256] = {0}, charCountSecond[256] ={0},counter;

    //If two string length are different, return false;
    if(strlen(str) != strlen(word)){
        return 0;
    }

    //Initialize the every index of the array by ascci value of character
    for(counter = 0 ; str[counter] != '\0' ; counter++){
        charCountFirst[str[counter]]++;
    }

    //Initialize the every index of the array by ascci value of character
    for(counter = 0 ; word[counter] != '\0' ; counter++){
        charCountSecond[word[counter]]++;
    }

    //Check all character are match or not; if not match return 0
    for(counter = 0 ; counter < 256 ; counter++){
        if(charCountFirst[counter] != charCountSecond[counter]){
            return 0;
        }
    }

    //Otherwise return 1;
    return 1;
}

int main()
{

    char line[MAX],str[200],*word=NULL;
    int i = 0;
    FILE *fptr = NULL;

    printf("Enter string: ");
    scanf("%s",str);

    printf("Enter the filename: ");
    scanf("%s", filename);

    /* open/VALIDATE file open for reading */
    if ((fptr = fopen (filename, "r")) == NULL) {
        perror ("fopen-a");
        return 1;
    }

    /* reuse buffer to read each line */
    /* fgets include '\n' in buffer if buffer of sufficient size */
    while (fgets (line, MAX, fptr) != NULL){

        word = strtok(line," ");
        while(word != NULL){
            int found = check_anagram(str,word);
            if(found == 1){
                count++;
                printf("%s\n",word);
            }
            word=strtok(NULL," ");
        }
    }

    //Close the file
    fclose(fptr);

    //Print total anagram found
    printf("%d\n",count);

    return 0;
}
