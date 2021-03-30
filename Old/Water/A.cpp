#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#define SIZE 1000

using namespace std;

class Stack
{
    private:
        int num[SIZE];
        int top;
    public:
        Stack();
        void push(int);
        int pop();
        bool isEmpty();
        bool isFull();
};

Stack::Stack(){
    top=-1;
}

bool Stack::isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool Stack::isFull(){
    if(top==(SIZE-1)){
        return true;
    }
    else{
        return false;
    }
}

void Stack::push(int n){

    if(!isFull()){
        ++top;
        num[top]=n;
    }
    else{
        cout<<"Overflow"<<endl;
    }
}

int Stack::pop(){
    if(isEmpty()){
        return 0;
    }
    return num[top--];
}

int main(){
    Stack stak;

    string line;
    string word[3];
    int data;
    while(getline(cin, line)){
        if(line.empty()){
            break;
        }
        istringstream str(line);
        string s;
        int j=0;
        while(str >> s){
            word[j]=s;
            j++;
        }

        if(word[0]=="push"){
            int pushData=stoi(word[1]);
            stak.push(pushData);
        }

        else{
            int popData=stak.pop();
            if(popData==0){
                cout<<"false ";
                break;
            }
            else{
                cout<<popData<<" ";
            }
        }
    }
    return 0;

}

