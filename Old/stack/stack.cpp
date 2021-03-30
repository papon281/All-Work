#include<iostream>
// #include "Stack.h"
using namespace std;

template<typename T>
Stack<T>::Stack(int Size){
    Capacity=Size;
    data = new T[Capacity];
    top = -1;
    count = 0;
}

template<typename T>
Stack<T>::~Stack(){
    delete[] data;
}

template<typename T>
void Stack<T>::push(T element){
        data[++top]=element;
        count++;
        if(count == count){
            T* newdata;
            newdata=new T[Capacity*2];
            for(int i=0;i<Capacity;i++){
                newdata[i]=data[i];
            }
            Capacity=Capacity*2;
            delete[] data;
            data=newdata;
        }
}

template<typename T>
bool Stack<T>::empty(){
 return top==-1;
}

template<typename T>
T Stack<T>::pop(){
    if(empty()){
        // throw EmptyStackException();
        return T();
    }
    else{
        return data[top--];
    }
}

template<typename T>
int Stack<T>::size(){
    return top + 1;
}

template<typename T>
int Stack<T>::capacity(){
    return Capacity;
}