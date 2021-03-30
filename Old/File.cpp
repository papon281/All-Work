#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    //it can create files, write information to files, and read information from files
    fstream file;
    //String type variable for input,output read and write data
    string input,output,line;
    int linecount=0;
    int alphabetCount[30]={0};
    cout<<"Please write the input and output file name:"<<endl;
    //user input filenames
    cin>>input>>output;
    //It can create file and read information from files
    ifstream inputFile;
    //it can create file and write information to file;
    ofstream outputFile;
    //Open input file for read
    inputFile.open(input.c_str(),ios::in);
    //open output file for write
    outputFile.open(output.c_str(),ios::out|ios::app);
    //Condition for check the input file is open or not
    //if input file not open then output the message to console
    if(!inputFile.is_open()){
        //Show this message on the screen
        cout<<"File is not exist";
    }
    //If file open then copy the input file data to another file
    else{
        //Copy the data, include blanks line
        outputFile << inputFile.rdbuf();
    }
    //Close the input file
    inputFile.close();
    //Open the input file for read data
    file.open(input.c_str());
    //Terminate the loop when complete read all the files
    while(getline(file,line)){
        //Length of string
        int length=line.size();
        //Convert the all alphabetic character into uppercase
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        //Index of array
        int i=0;
        //Loop for count the Alphabetic character individual in a file present for all lines.
        for(char ch='A';ch<='Z';ch++){
            //Store the occurrences of character in a line
            int letterCount=count(line.begin(),line.end(),ch);
            //Store the alphabetic character array
            alphabetCount[i]=alphabetCount[i]+letterCount;
            //increase the index value;
            i++;
        }
        //count the line number in the input file
        linecount++;
    }
    //close the input file
    file.close();
    //open the output file
    file.open(output.c_str());
    //Write new data in output file
    file<<"The number of lines in the input file is "<<linecount<<"."<<endl;
    //Calculate the size of array
    int size=sizeof(alphabetCount)/sizeof(alphabetCount[0]);
    char ch;
    //loop for write the data of individual alphabet number
    for(int i=0,ch='A';i<size,ch<='Z';i++,ch++){
        //condition for write the alphabet
        if(alphabetCount[i]>0){
            //Write to the file
            file<<(char)ch<<" appears "<<alphabetCount[i]<<" times."<<endl;
        }
    }
    file<<endl;
    file.close();
    return 0;
}
