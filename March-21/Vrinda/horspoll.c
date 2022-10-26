#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 1024

/*define table size*/
int table[256];


/* Method for preprocess */
void shiftTable(char* pattern)
{
    int i,j;
    int len = strlen(pattern);

    //Initialize the table to default value, which is length of pattern string
    for(i = 0; i < 256; i++)
    {
        table[i] = len;
    }

    //Initialize table index with the ascii value of character
    for(j = 0; j < len-1; j++)
    {
        table[pattern[j] + 128] = len - 1 - j;
    }
}


//Method for check the string is same or not
bool same(char* text, char* pattern, int j)
{
    int i = strlen(pattern) - 1;

    //Check if every text index value is equal or not for pattern index
    while(text[i + j] == pattern[i])
    {
        //If i is 0 return true;
        if(i == 0)
        {
            return true;
        }

        //Decrement the value of i
        i = i-1;
    }

    //else return false
    return false;
}


//Method for find the match pattern
int horspool(char* pattern, char* source)
{
    int pn = strlen(pattern);
    int tn = strlen(source);
    int j = 0;

    //Search the source, while the pattern can still be within it. */
    while( pn + j < tn)
    {
        //Check if the pattern is same or not; if same return the index
        if( same ( source , pattern , j ) )
        {
            return j;
        }

        //else increment the value of index
        j += table [ source [ j + pn - 1 ] + 128 ];
    }

    //If not found match return -1
    return -1;
}

//Driver method
int main()
{
    char line[MAX] , str[200] , filename;
    int i = 0 , pos = 0 , count = 0;
    FILE *fptr = NULL;

    //User input string
    printf("Enter string: ");
    scanf("%s",str);

    //Call method shifttable for preprocess
    shiftTable(str);

    //User input file name
    printf("Enter the filename: ");
    scanf("%s", filename);

     /* open/VALIDATE file open for reading */
    if ((fptr = fopen (filename, "r")) == NULL)
    {
        perror ("fopen-a");
        return 1;
    }

     /* reuse buffer to read each line */
    /* fgets include '\n' in buffer if buffer of sufficient size */
    while (fgets (line, MAX, fptr) != NULL)
    {
        //Calling the method for find the pattern match
        pos = horspool(str,line);

        //If pattern is match the increment the counter
        if(pos >= 0)
        {
            count++;
        }
    }

    //Close the file
    fclose(fptr);

    //Print the total number of match
    printf("%d\n",count);

    return 0;
}
