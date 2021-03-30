#include<stdio.h>
#include<math.h>
#include "primes.h"

void primes(long long int n){
    long long lim = sqrt(n), i;
    for(i = 2; i <= lim; i++){
        if(n % i == 0){
            while(n % i == 0){
                printf("%lld ", i);
                n /= i;
            }
            lim = sqrt(n);
        }
    }
    if(n > 1){
        printf("%lld", n);
    }
    printf("\n");
}