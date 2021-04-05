#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mstring.h"

void strrev(char* string){
    int length = strlen(string),i;
    for(i=0;i<length/2;i++){
        char ch = string[i];
        string[i] = string[length-1-i];
        string[length-1-i] = ch;
    }
}