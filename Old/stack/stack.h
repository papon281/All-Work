#ifndef __MY_STACK__
#define __MY_STACK__
#include <exception>
#include <iostream>

template<typename T>
class Stack{
    T* data; // the array to store data
    int cap; // capacity of the stack
    int count; // current number of element in the stack
public:
    Stack(int size = 4);
    ~Stack();
    T pop();
    void push(T);
    bool empty();
    int size();
    int capacity();
};

class EmptyStackException : public std::exception {
public:
    const char * what () const throw ()
    {
    	return "Stack is empty";
    }
};


template<typename T>
Stack<T>::Stack(int size){
    cap = size;
    data = new T[cap];
    count = 0;
}

template<typename T>
Stack<T>::~Stack(){
    delete[] data;
}

template<typename T>
void Stack<T>::push(T element){
        data[count++]=element;
        if(count == cap){
            T* newdata;
            newdata=new T[cap * 2];
            for(int i = 0; i < cap; i++){
                newdata[i] = data[i];
            }
            cap = cap * 2;
            delete[] data;
            data = newdata;
        }
}

template<typename T>
bool Stack<T>::empty(){
    return count == 0;
}

template<typename T>
T Stack<T>::pop(){
    if(empty()){
        throw EmptyStackException();
    }
    else{
        count--;
        return data[count];
    }
}

template<typename T>
int Stack<T>::size(){
    return count;
}

template<typename T>
int Stack<T>::capacity(){
    return cap;
}

#endif // __MY_STACK__