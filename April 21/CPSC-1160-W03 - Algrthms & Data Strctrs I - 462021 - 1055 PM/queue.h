#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;


template <typename T>
class queue{
    public:
        //Constructor
        queue();
        //Add item to the end of queue
        void enqueue(T);
        //Remove/Return the item at the start of thwe queue
        T dequeue();
        //Look at the start of the queue
        T front();
        //Check if the queue is empty
        bool isEmpty();
        void print();

        //Destructor
        ~queue();
        //Copy Constructor
        queue(const queue&);
        //Overload
        const queue& operator = (const queue&);

        int getSize();

    private:
        struct node{
            T data;
            node* next;
        };
        node* head;
        node* tail;
        node* deleteall(node*);
        node* copy_list(node*);
        int size;
};

template<typename T>
int queue<T>::getSize(){
    return size;
}

template <typename T>
queue<T>::queue(){
    head =  nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
queue<T>:: ~queue(){
    node * temp;
    deleteall(head);
    cout<<"-------------------Delete-----------------------"<<endl;
}

template <typename T>
queue<T>::queue(const queue & f){
    head = copy_list(f.head);
    tail=f.tail;
    cout<<"-------------------Copy-------------------------"<<endl;
    size = f.size;
}

template <typename T>
const queue<T>& queue<T>::operator=(const queue<T>& f){
    if(this == &f){
        cout<<"-------------------Assingment-------------------"<<endl;
        return *this;
    }
    deleteall(head);
    deleteall(tail);
    head = copy_list(f.head);
    tail = copy_list(f.tail);
    size = f.size;
    cout<<"-------------------Assingment-------------------"<<endl;
    return *this;
}

template<typename T>
typename queue<T>::node* queue<T>::deleteall(node* p){
   if(!p){
      return p;
   }
   queue<T>::node*n = p->next;
   delete p;
   return deleteall(n);
}

template<typename T>
typename queue<T>::node* queue<T>::copy_list(node* p){
    if(!p){
        return p;
    }
    return new node{p->data,copy_list(p->next)};
}

template <typename T>
void queue<T>::enqueue(T x){
    if(!head){
        tail = new node{x,nullptr};
        head = tail;
    }
    else{
        tail->next = new node{x,nullptr};
        tail = tail->next;
    }
    size++;
}

template <typename T>
bool queue<T>::isEmpty(){
    return !head;
}

template <typename T>
T queue<T>::front(){
    if(isEmpty()){
        cout<<"Queue is Empty";
        exit(1);
    }
    return head->data;
}

template <typename T>
T queue<T>::dequeue(){
    T ret_val = front();
    node* tmp = head->next;
    delete head;
    head = tmp;
    if(!head){
        tail = head;
    }
    size--;
    return ret_val;

}

template <typename T>
void queue<T>::print(){
    if(isEmpty()){
        cout<<"List is Empty"<<endl;
        return;
    }
    node* p = head;
    while(p){
        cout<<p->data<< "->";
        p = (p->next);
    }
    cout<<"nullptr "<<endl;

}
#endif
