// Author: Gladys Monagan 
// Commands and command processing including a function to make 
// a map to store commands in
// Course: CPSC 2150
// Copyright 2021

#include "Commands.h"
#include <sstream>    // std::stringstream
#include <map>        // std::map
#include <iostream>   // std::cin std::cout 
#include <string>     // std::string
#include <fstream>    // std::ifstream std::ofstream

using std::cout, std::cin, std::string;
using std::pair, std::map;

// output the commands available
void printCommandMenu() {
   cout << "\n --------------choose a command  -------------------------------\n";
   cout << "(i) - input the file name that contains the graph \n";
   cout << "(o) - output the graph to std::cout\n";
   cout << "(n) - number of vertices in the graph\n";
   cout << "(c) - determines whether the graph is connected or not\n";
   cout << "(f) - find a cycle\n";
   cout << "(l) - list the connected components (one set of vertices per line)\n";
   cout << "(t) - twin the graph by making a copy\n";
   cout << "(d) - done with the graph\n";
   cout << "(m) - mention or comment, the subsequent line is ignored\n";
   cout << "(q) - quit the program altogether\n";
   cout << "(p) - calculate the path length between two vertices\n";
   cout << " -----------------------------------------------------------------\n"; 
}

// make an associative array of the character (that will be obtained from input)
// and its associated command
void buildCommands(map<char, Commands>& commands) {
   commands.insert(pair('i', INPUT));
   commands.insert(pair('o', OUTPUT));
   commands.insert(pair('n', NUMBER));
   commands.insert(pair('c', CONNECTED));
   commands.insert(pair('f', FIND_CYCLE));
   commands.insert(pair('l', LIST_COMPONENTS));
   commands.insert(pair('t', TWIN));
   commands.insert(pair('d', DONE));
   commands.insert(pair('m', MENTION));
   commands.insert(pair('q', QUIT));
   commands.insert(pair('p', PATH));
}

// read from standard input a command and obtain the first letter of that 
// command to match it to a corresponding value from the enum type Commands
// if notInteractive, the command read is echoed to standard output
// postcondition:
//    returns a command from Commands (including INVALID)
Commands getCommand(map<char, Commands>& commands, bool notInteractive) {
   cout << "\ncommand: ";
   string commandStr;
   cin >> commandStr;
   std::stringstream ss(commandStr);
   char ch;
   ss >> ch;
   if (notInteractive) cout << commandStr << "\n";  // echo what was read
   Commands cmd = INVALID;
   if (commands.find(ch) != commands.end()) cmd = commands[ch];
   return cmd;
}

// read from standard input a single word and check if the first
// letter corresponds to 'y' or 'Y' (implying a yes)
// return true if the string read from cin starts with 'y' or 'Y', false otherwise
// if notInteractive, the answer read is echoed onto standard output
bool yesAnswer(bool notInteractive) {
   string answerStr;
   cin >> answerStr;
   if (notInteractive) cout << answerStr << "\n";
   return (answerStr[0] == 'Y' || answerStr[0] == 'y');
}

// reset the input stream (possibly out of its fail state) and clear the buffer
// postcondition:
//    fin is ready to read again
void clearClean(std::istream &fin) {
   static const int MAX_CHARACTERS_IN_BUFFER = 250;
   fin.clear();
   fin.ignore(MAX_CHARACTERS_IN_BUFFER, '\n');
}

// consume the end-of-line of the previous fin
// read a line using fin and output it to fout if notInteractive
void getLineOutputLine(std::istream& fin, std::ostream& fout, bool notInteractive) {
   string line;
   std::getline(fin, line); // consume the end-of-line
   std::getline(fin, line);
   if (notInteractive) fout << line << "\n";
}