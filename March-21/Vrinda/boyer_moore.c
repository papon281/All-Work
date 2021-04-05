#include<stdio.h>
#include<string.h>
#include<limits.h>

#define MAX 1024
#define NO_OF_CHARS 256

/* A utility function to get maximum of two integers */
int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/*The preprocessing function for Boyer Mooore's bad
 character heuristic */
void badCharHeuristic( char* str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    //Initialize all occurenecs as -1
    for(i = 0 ; i < NO_OF_CHARS ; i++){
        badchar[i] = -1;
    }

    /* Fill the actual value of last occurrence of a character */
    for(i = 0 ; i < size ; i++){
        badchar[(int) str[i] + 128] = i;
    }
}

/* A pattern searching function that uses Bad
   Character Heuristic of Boyer Moore Algorithm */
int boyer_Moore(char* pattern, char* source){

    int m = strlen(pattern);
    int n = strlen(source);

    int badchar[NO_OF_CHARS];

/* Fill the bad character array by calling the preprocessing function babCharHeuristic() for given pattern */
    badCharHeuristic(pattern, m, badchar);

    int s = 0; // s is shift of the pattern with respect to text
    int count  = 0;
    while(m + s < n)
    {
        int j = m-1;
        /* Keep reducing index j of pattern while characters of
        pattern and text are matching at this shift s */
        while(j >= 0 && pattern[j] == source[s+j])
        {
            j--;
        }

        /* if the pattern is present at current shift, then index j will become -1 after the above loop */
        if(j < 0)
        {
            count++;
            if(s + m < n){
                /* The condition s+m < n is necessary for the case when pattarn occers at the end of text */
                s= s+( m - badchar [ source [ s + m ] + 128 ] );
            }
            else{
                s = s + 1;
            }
        }
        else
            /*we may get positive and negative occurrence of bed character in pattern is on the right side of the current */
            s = s + max ( 1 , j - badchar[ source [ s + j ] + 128 ] );
    }
    return count;
}

/*Driver program to test above function */
int main()
{
    char line[MAX] , str[200], char filename[50];
    int i = 0 , count = 0;
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

    /* reuse buffer to read each line */
      /*fgets include '\n' in buffer if buffer of sufficient size */
    while (fgets (line, MAX, fptr) != NULL)
    {

        count += boyer_Moore( str , line);
    }
    fclose(fptr);
    printf("%d\n", count);
    return 0;
}
