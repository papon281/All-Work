#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int countMatchPattern ( char* str, char* line )
{
    int m , n;
    m = strlen(str);
    n = strlen(line);
    int match = 0;

    /* A loop to slide pattern[] one by one */
    for(int i = 0 ; i < n ; i++){

        int j;
        /* For current index i, check for pattern match */

        for( j = 0 ; j < m && i + j < n ; j++){

            if( line[ i + j ] != str[ j ] ){
                break;
            }
        }

        // if pattern[0...M-1] = text[i, i+1, ...i+M-1]
        if(j == m){
            match++;
        }
    }
    return match;
}

/* Driver program to test above function */
int main()
{

    char line[MAX],str[200] , filename[50];
    int i = 0 , count = 0;
    FILE *fptr = NULL;

    printf("Enter string: ");
    scanf("%s",str);

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
        count += countMatchPattern(str,line);;
    }

    //Close the file
    fclose(fptr);

    //Print the total pattern found
    printf("%d\n",count);
    return 0;
}
