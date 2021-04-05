#include<iostream>
using namespace std;
//Declare template T Type
template<typename T>
//Create template method for find the minimum between two values
T Minimum(T a,T b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}
int main(){
    int a,b;
    //Input the values
	cin>>a>>b;
	//Check the equality between two number
	if(a==b){
		cout<<"The numbers are equal."<<endl;
	}
	else{
        //call the function
		int min=Minimum<int>(a,b);
        //print the minimum between two number
		cout<<min<<endl;
	}
	return 0;
}
