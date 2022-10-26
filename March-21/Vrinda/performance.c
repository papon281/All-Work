#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<time.h>
#include<stdbool.h>

#define MAX 1024

int countMatchPattern(char* str, char* line)
{
    int m,n;
    m = strlen(str);
    n = strlen(line);
    int count = 0;

    /* A loop to slide pattern[] one by one */
    for(int i=0; i<=n-m; i++)
    {

        int j;
        /* For current index i, check for pattern match */

        for(j=0; j<m; j++)
        {

            if(line[i+j]!= str[j])
            {

                break;

            }

        }

        // if pattern[0...M-1] = text[i, i+1, ...i+M-1]
        if(j == m)
        {
            count++;
        }
    }
}

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


/* Driver program to test above function */
int main()
{

    char line[MAX] , str[200] , filename[50];
    int i = 0,count=0,pos=0;
    FILE *fptr = NULL;

    printf("Enter string: ");
    scanf("%s",str);

    printf("Enter the filename: ");
    scanf("%s",filename);

    /* open/VALIDATE file open for reading */
    if ((fptr = fopen (filename, "r")) == NULL)
    {
        perror ("fopen-a");
        return 1;
    }

    /* for time calculation */
    clock_t beginTime1, beginTime2 ;
    clock_t endTime1, endTime2;

    beginTime1 = clock();

    /* reuse buffer to read each line */
    while (fgets (line, MAX, fptr) != NULL)
    {
        /* fgets include '\n' in buffer if buffer of sufficient size */
        countMatchPattern(str,line);
    }

    endTime1 = clock();

    double total_t1 = ( endTime1 - beginTime1 ) / (double)CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t1);

    beginTime2 = clock();
    while (fgets (line, MAX, fptr) != NULL)
    {
        pos = horspool(str,line);
    }

    endTime2 = clock();
    double total_t2 = ( endTime2 - beginTime2 ) / (double)CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t2);
    fclose(fptr);
    return 0;
}
