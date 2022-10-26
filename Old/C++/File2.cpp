#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    //it can create files, write information to files, and read information from files
    fstream file;
    //It can create file and read information from files
    ifstream inputFile;
    //it can create file and write information to file;
    ofstream outputFile;
    //String type variable
    string line;
    //Open input file for read
    inputFile.open("Input.txt",ios::in);
    //open output file for write
    outputFile.open("Output.txt",ios::out|ios::app);
    //Condition for check the input file is open or not
    //if input file not open then output the message to console
    if(!inputFile.is_open()){
        cout<<"File is not open"<<endl;
    }
    //If file open then copy the input file data to another file
    else{
        outputFile << inputFile.rdbuf();
    }
    inputFile.close();
    file.open("Output.txt");
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
    return 0;
}
