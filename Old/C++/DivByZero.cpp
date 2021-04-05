#include<iostream>
#include<exception>
using namespace std;
//Exception class
class DivByZero: public exception{
    public:
        //Method for calculated quotient and return int type value
        int Quotient(int numerator, int denominator){
            //condition for throw exception
            if(denominator==0){
                throw("There was an attempt to divided by zero!");
            }
            //return the integer division if no exception occur
            return (numerator/denominator);
        }
};
int main(){
    //Initializing two integer type variable
    int numerator,denominator;
    cout<<"Enter numerator: ";
    //Input the values
    cin>>numerator;
    cout<<"Enter denominator: ";
    cin>>denominator;
    //create Constructor for class
    DivByZero divbyzero;
    //Try block
    try{
        //call the method quotient and return the integer division
        int quotient=divbyzero.Quotient(numerator,denominator);
        cout<<quotient<<endl;
    }
    //Catch block for catch the exception
    catch(const char* e){
        //Print the message
        cout<<e<<endl;
    }
    return 0;
}
