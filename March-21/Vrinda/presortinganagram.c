#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

//Method for sort the string
void sort(char str[]){
    char temp;
    int i,j;
    for(i = 0 ; i < strlen(str) - 1 ; i++){
        for(j = i + 1 ; j < strlen(str) ; j++){
            if(str[i] > str[j]){
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

//method for check the anagram
int check_anagram(char* str, char* word){

    int i;

    //Check the length of two string is equal or not
    if(strlen(str) != strlen(word)){
        return 0;
    }

    //Check the two string are anagram or not
    else{
        sort(str);
        sort(word);
        //Check every character index by index. If not match, then return 0;
        for(i = 0 ; i < strlen(str) ; i++){
            if(str[i] != word[i]){
                return 0;
            }
        }
    }

    //if all conditions are true, return 1;
    return 1;
}

//Driver method
int main()
{

    char line[MAX] , str[200] , *word=NULL , temp[MAX], filename[50];
    int i = 0,found=0,count=0;
    FILE *fptr = NULL;

    //User input string
    printf("Enter string: ");
    scanf("%s",str);

    //User input filename
    printf("Enter the filename: ");
    scanf("%s",filename);

    /* open/VALIDATE file open for reading */
    if ((fptr = fopen (filename, "r")) == NULL) {
        perror ("fopen-a");
        return 1;
    }

    /* reuse buffer to read each line */
    /* fgets include '\n' in buffer if buffer of sufficient size */
    while (fgets (line, MAX, fptr) != NULL){

        //Split the text into word
        word = strtok(line," ");

        while(word != NULL){

            //Copy word into temp for print the anagram string
            strcpy(temp,word);

            //Call the method for check the anagram
            int found = check_anagram(str,word);

            //if anagram found, then increment the counter and print the current word
            if(found == 1){
                count++;
                printf("%s\n",temp);
            }

            //Initialize the word again null
            word=strtok(NULL," ");
        }
    }

    //Close the input file
    fclose(fptr);

    //Print the total word found
    printf("%d\n",count);
    return 0;
}
