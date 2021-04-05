#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "codes.h"

char encrypt(int start,int offset,char c){
    int ascii_value=(int)c;
    int binary[8];
    int i=0,rem,j,convertedValue=0;
    while(ascii_value > 0){
        rem=ascii_value % 2;
        ascii_value=ascii_value/2;
        binary[i]=rem;
        i++;
    }

    int pw = 1;
    for(j = 7; j >=0; j--){
        if(binary[j] == 1){
            convertedValue += pw;
        }
        pw = pw * 2;
    }

    convertedValue = convertedValue<<start;
    convertedValue = convertedValue>>offset;
    return ((char)convertedValue);
}


char decrypt(int start,int offset,int cipher){
    cipher = cipher << offset;
    cipher = cipher >> start;
    int binary[8];
    int i=0,rem,j,convertedValue=0;
    while(cipher > 0){
        rem=cipher % 2;
        cipher=cipher/2;
        binary[i]=rem;
        i++;
    }

    int pw = 1;
    for(j = 7; j >=0; j--){
        if(binary[j] == 1){
            convertedValue += pw;
        }
        pw = pw * 2;
    }

    return ((char)convertedValue);
}