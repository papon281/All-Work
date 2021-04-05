#include<iostream>

using namespace std;

int increment(int n){
    int cnt =0,sum=0;
    for(int i=0;i<n;i++){
        sum++;
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    cout<<increment(n)<<endl;
}
