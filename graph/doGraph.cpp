// Program to use (test) graph algorithms.
// Commands supported 
// -> input the file name that contains the graph
// -> output the graph to std::cout
// -> output the number of vertices in the graph
// -> determine if the graph is connected
// -> find a cycle
// -> list all the connected components of the graph
// -> copy the graph and manipulate the copy (the twin)
// -> calculate the path length from a vertex to another vertex
// All the input from a user comes from standard input (std::cin) and the output
// with results and questions for the user are done to standard output (std::cout).

// usage: doGraph -batch < inFile.txt > outFile.txt
// to run program non-interactively obtaining commands from inFile.txt
// putting the output into outFile.txt
//
// usage: doGraph
// renders an interactive session with commands

// Author: Gladys Monagan
// DO NOT POST THIS ANYWHERE.
// This code is copyrighted.
// Use it exclusively for CPSC 2150 at Langara College in Vancouver
#include <fstream>
#include <string>
#include <iostream>
#include "Commands.h"
#include "Graph.h"

using std::cout, std::cin, std::ifstream, std::istream, std::string, std::map;

// process the commands
Commands process(map<char, Commands> commands, Graph& graph, bool notInteractive);

// read from standard input the file name of the undirected simple graph
// if the file CAN be opened, read the graph from that file
// precondition:
//    the graph input file has an integer n for the number of vertices such
//    that every vertex v is 0 <= v < n
//    following the number of vertices n,  
//    there are pairs of integers corresponding to edges (i, j) 
//    such that 0 <= i < n and 0 <= i < n
//    the edges are undirected 
// postcondition: 
//    the graph with the data if reading was successful
//    the input stream cin is cleared if an error was encountered
//    return true if the graph was read successfully, false otherwise
bool inputGraph(Graph& graph, bool notInteractive) {
   bool success = true;
   string fileName;
   cout << "enter the file name that has the graph: ";
   cin >> fileName;
   if (notInteractive) cout << fileName << "\n";
   ifstream fin;
   fin.open(fileName);
   if (!cin.good() || (!fin.good()) ) {
      cout << "ERROR in reading/opening the graph file \"" << fileName << "\"\n";
      clearClean(cin);
      success = false;
   }
   else {
      fin >> graph;
      fin.close();
   }
   return success;
}

// make a copy of graph using the copy constructor
// test that some properties are the same and call a few commands on it
// the destructor is implicitly called once 'other' goes out of scope
// to get out of the "twin mode", a normal DONE is needed
void makeTwinNCommand(const Graph& graph, map<char, Commands> commands,
                      bool notInteractive) {
   Graph other = graph;
   if ( (other.hasCycle() != graph.hasCycle()) || 
        (other.isConnected() != graph.isConnected()) ){
      cout << "ERROR: twin is not identical to graph\n";
   }
   else {
      Commands cmd;
      do {
         cout << "\nfor twin graph ";
         cmd = process(commands, other, notInteractive);
      } while (cmd != DONE);
   }
}

// calculate the path length between two vertices which are obtained using std::cin
void pathLength(const Graph& graph, bool notInteractive) {
   cout << "enter the starting vertex and the destination vertex: ";
   int vStart, vDest;
   cin >> vStart >> vDest;
   if (!cin.good()) {
      cout << "ERROR the starting vertex and destination vertex must be numeric\n";
      clearClean(cin);
      return;
   }
   if (notInteractive) {
      cout << "\n     source vertex = " << vStart;
      cout << "\ndestination vertex = " << vDest << "\n";
   }
   cout << "path length from vertex " << vStart << " to vertex " << vDest << " is ";
   cout << graph.pathLength(vStart, vDest);
   cout << "\n";
}

// call the various functions to do what is needed
Commands process(map<char, Commands> commands, Graph& graph, bool notInteractive) {   
   Commands command = getCommand(commands, notInteractive);
   switch (command) {
      case INPUT:
         if (!inputGraph(graph, notInteractive)) 
            cout << "enter the graph file name again!\n";
         break;
      case OUTPUT:
         cout << graph;
         break;
      case NUMBER:
         cout << "the graph has " << graph.numberOfVertices() << " vertices\n";
         break;
      case CONNECTED:
         cout << "the graph is ";
         if (!graph.isConnected()) cout << "NOT ";
         cout << "connected\n";
         break;
      case FIND_CYCLE:
         if (graph.hasCycle()) 
            cout << "the graph has at least one cycle\n";
         else
            cout << "no cycles\n";
         break;
      case LIST_COMPONENTS:
         graph.listComponents(cout);
         break;
      case TWIN:
         makeTwinNCommand(graph, commands, notInteractive);
         break;
      case PATH:
         pathLength(graph, notInteractive);
         break;
      case MENTION:
         getLineOutputLine(cin, cout, notInteractive);
         break;
      case DONE:
      case QUIT:
         // the task is done
         break;
      case INVALID:
         cout << "invalid command, please input again!\n";
         break;
      default:
         std::cerr << "**** ERROR in the switch of process ***\n";
         break;
   }
   return command;
}

// determine if the "-batch" option was entered meaning that the
// session is NOT interactive
// return true if the string matches -batch, false otherwise
bool notInteractiveOption(string option) {
   return option == "-batch";
} 

// if the session is interactive, echo the input
// read a graph, process it and until DONE continue
// finish once the command DONE and/or QUIT
int main(int argc, char* argv[]) {
   bool notInteractive = false;
   if (argc > 1) notInteractive = notInteractiveOption(argv[1]);
   map<char, Commands> commands;
   buildCommands(commands);

   Commands cmd;
   do {
      if (!notInteractive) printCommandMenu();
      Graph graph; 
      do {
         cmd = process(commands, graph, notInteractive);
      } while (cmd != DONE && cmd != QUIT); 
   } while (cmd != QUIT); 
   return 0;
}
