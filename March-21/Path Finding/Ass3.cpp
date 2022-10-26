#include<iostream>
#include<vector>
#include<fstream>
#include "stack.h"
using namespace std;
/**
 * A simple c++ program that tries to guess the path that sum up zero.
 * @author Karan Sahni
 */
string getName(){
    string name;
    cout << "Name of the File with Matrix" << std:: endl;
    cin >> name;
    return name;
}
/**
 * This method get the pathLength from the user
 * @return int Length of the path
 */
int getPathLength(){
    int path;
    cout << "How long of a path you are looking for?" << std:: endl;
    cin >> path;
    return path;
}
/**
 * This method return the 2D mterix from the text file
 * @pram name The name of the text file
 * @return 2-D Vector 2-D Matrix from the text file
 */
vector<vector<char>> getVector(const string &name){
    string line = " ";
    int row ;
    int column ;
    ifstream in;
    in.open(name);
    in >> row >> column;

    vector<vector<char>> v( row ,vector<char> (column, 0));
    if(in.is_open()){
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                in >> v[i][j];
            }
        }
    }
    return v;
}
/**
 * This method tries to find the path from the matrix in given PathLength
 * @pram vector v The input entered by user
 * @pram int pathLength Length of the path
 * @pram int x postion of Row
 * @pram int y positon of column
 * @pram char d character ad direction
 * @pram int count number of comparison
 * @pram int sum sum of the char in the path
 * @return 2-D Vector Matrix showing the path that sum up zero
 */

vector<vector<char>> path_finder(const vector<vector<char>> &v, int &pathLength, int x, in t y, char d, int &count, int &sum){
    bool found = false;
    int row = v.size();
    int column = v[0].size();
    std::vector<std::vector<char>> c (row , std::vector<char> (column, '-'));
    if(count == pathLength && sum == 0){
        found = true;
        return c;
    }
    if(count <= pathLength){
        if(x <= row && y <= column && x >= 0 && y >= 0){
            if( ++count && v[x][y] == '+'){
                    ++sum;
                    c[x][y] = d;
                }
            else{
                    --sum;
                     c[x][y] = d;
                }
        found = false;
        path_finder(v,pathLength,x,y+1,d,count,sum);
        }
    }
    else if(!found){
        path_finder(v,pathLength,x,y-1,'<',count,sum);
    }
    else if(!found){
    path_finder(v,pathLength,x,y+1,'>',count,sum);
    }
    else if(!found){
        path_finder(v,pathLength,x,y-1,'^',count,sum);
    }
    return c;
}

int main(){
    int sum;
    int count;
    std::string name = getName();
    int pathLength = getPathLength();
    std::vector<std::vector<char>> v;
    v = getVector(name);
    std::vector<std::vector<char>> c;
    c = path_finder(v,pathLength,0,0,'V',count,sum);
    int row = c.size();
    int column = c[0].size();
    for(int i = 0; i < row;  i++)
    {
        for(int j = 0; j < column;  j++)
        {
            std::cout << c[i][j] << " ";
        }
    }
}
