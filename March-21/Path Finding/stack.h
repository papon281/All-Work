#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class stack{
    public:
        stack();
        struct path{
            int x,y;
            char c;
            int sum;
            //This method return the string containing all the variable in the point struct
            string getClass() {
                string x1 = to_string(x);
                string y1 = to_string(y);
                string z1 = to_string(sum);
                return "(" + x1 + "," + y1 + "," + z1 + ") " + "is class " + c;
            }
        };
        void push(path x);
        path pop();
        path peek();
        bool isEmpty();

        //Destructor
        ~stack();
        //Copy Constructor
        stack(const stack&);
        //Overload
        const stack& operator=(const stack&);

    private:
        struct node{
            path data;
            node* next;
        };
        node* top;
};

stack::stack(){
    top = nullptr;
}

bool stack::isEmpty(){
    return !top;
}

void stack::push(path x){
    top = new node(x,top);
}

path stack::peek(){
    if(isEmpty()){
        cout<<";ist is Empty";
        exit(1);
    }
    return top->data;
}

path stack::pop(){
    path ret_val = peek();
    node* tmp = top->next;
    delete top;
    top = tmp;
    return ret_val;
}


/**
 * This method print out each char of fun_list
 * @pram ostream out The output stream which printout the elements
 * @pram fun_list l fun_list to be printed out
 * @return ostream output stream priting out letters
 */
ostream& operator <<(ostream& out,  fun_list& l){

    for(int i=0; i<l.size; i++){
        out<< l.word[i] << " ";
    }
    out<< endl;
    return out;
}
#endif
