#include<stdio.h>
#include "pascal.h"

void pascal(int n){
    int previous=1,i;
    printf("%d",previous);
    for(i = 1; i <= n; i++){
        int current=(previous*(n-i+1))/i;
        printf(" %d",current);
        previous=current;
    }
    printf("\n");
}