#include <iostream>
#include "ArrayUtils.h"
#include "Stack.h"
#include "Employee.h"
using namespace std;

void testStackUnderflow() {
    try{
        Stack<int> st;
        st.push(1);
        st.pop();
        st.pop();
        cout<<"did not catch exception"<<endl;
    } catch(EmptyStackException ex){
        cout<<"caught EmptyStackException"<<endl;
    }
}

void testStackGrowth(){
    Stack<int> stack(4);
    cout<<"Initial capacity of stack: "<<stack.capacity()<<endl;
    for(int i=1; i <=9 ;i++){
        stack.push(i);
        cout<<"Pushed "<<i<<endl;
        if(i == 5){
            cout<<"Current capacity of stack is: "<<stack.capacity()<<endl;
        } else if(i == 9){
            cout<<"Current capacity of stack is: "<<stack.capacity()<<endl;
        }
    }
    while(!stack.empty()){
        cout<<"Poped "<<stack.pop()<<endl;
    }
}

void testReverseIntegers(){
    int n = 12;
    int ar[n];
    for(int i = 0; i< n; i++){
        ar[i] = i;;
    }
    cout<<"Inital array"<<endl;
    for(int i = 0 ; i < n; i++){
        cout<<ar[i]<<endl;
    }
    int *res = ArrayUtils<int>::reverse(ar, n);
    cout<<"Reversed array:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<res[i]<<endl;
    }
}

void testReverseStrings(){
    int n = 12;
    string ar[n];
    for(int i = 0; i< n; i++){
        ar[i] = "";
        ar[i] += (char)(i+'A');
    }
    cout<<"Inital array"<<endl;
    for(int i = 0 ; i < n; i++){
        cout<<ar[i]<<endl;
    }
    string *res = ArrayUtils<string>::reverse(ar, n);
    cout<<"Reversed array"<<endl;
    for(int i = 0; i < n; i++){
        cout<<res[i]<<endl;
    }
}

void testReverseEmployees(){
    int n = 12;
    Employee ar[12];
    for(int i = 0; i < n; i++){
        string name="";
        name += (char)(i+'A');
        ar[i] = Employee(name, i);
    }

    cout<<"Inital array"<<endl;
    for(int i = 0 ; i < n; i++){
        cout<<ar[i].toString()<<endl;
    }
    cout<<endl;
    Employee *res = ArrayUtils<Employee>::reverse(ar, n);
    cout<<"Reversed array"<<endl;
    for(int i = 0; i < n; i++){
        cout<<res[i].toString()<<endl;
    }
}


int main(){
    testStackUnderflow();
    cout<<endl;
    testStackGrowth();
    cout<<endl;
    testReverseIntegers();
    cout<<endl;
    testReverseStrings();
    cout<<endl;
    testReverseEmployees();
    return 0;
}
