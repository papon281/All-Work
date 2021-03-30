#include<iostream>
using namespace std;
//method for calculating the minimum between two value
int min (int a, int b){
    if (a < b)
        return a;
    else
        return b;
}
int main(){
    int a,b;
    //input two value
    cin>>a>>b;
    //Check for equality
    if(a==b){
        //print the message
        cout<<"The numbers are equal";
    }
    else{
        //Call the method
        int minimum=min(a,b);
        //Print the result
        cout<<minimum;
    }
    return 0;
}
