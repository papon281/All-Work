#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include "mmath.h"

int find_gcd(int n,int m);

long long int fact(int n){
    int i;
    long long int ans=1;
    if(n <= 1){
        return ans;
    }
    else{
        for(i=2;i<=n;i++){
            ans=ans*i;
        }
        return ans;
    }
}

long long int nchoosek(int n,int k){
    long long int ans=fact(n)/(fact(k)*fact(n-k));
    return ans;
}

int prime(long long int n){
    if(n==2){
        return 1;
    }
    else if(n%2 == 0 || n < 2){
        return 0;
    }
    else{
        int i;
        int lim = sqrt(n);
        for(i = 3; i <= lim; i++){
            if(n % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

int gcd(int n,int m){
    if(m==0){
        return n;
    }
    return gcd(m,n%m);
}

int lcm(int n,int m){
    int gd=gcd(n,m);
    return ((n*m)/gd);
}

char bitrev(char ch){
    int num = (int) ch;
    int res = 0, i;
    for(i = 7; i >= 0; i--){
        if(num & (1<<i)){
            res |= (1<<(7-i));
        }
    }
    return (char) res;
}
