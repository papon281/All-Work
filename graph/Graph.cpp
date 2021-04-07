// Student Name: 

#include <iostream>
#include <limits> // for declaration of 'numeric_limits' for in
#include <ios>    // for declaration of 'streamsize' for in
#include "Graph.h"

Graph::Graph() {

}

int Graph::numberOfVertices() const {

}

// get stream out of the fail state and clear the buffer
void Graph::clearClean(std::istream& in) {
   in.clear();
   in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   
}

// read the graph by first deleting the current graph
std::istream& operator >> (std::istream& in, Graph& graph) {

   return in;
}

std::ostream& operator << (std::ostream& out, const Graph& graph) {
   
   return out;
}

bool Graph::isConnected() const {
 
}

bool Graph::hasCycle() const {
 
}

void Graph::listComponents(std::ostream& out) const {

}

// postcondition:
//    deep copy of the rtSide was made      
Graph& Graph::operator = (const Graph& rtSide) {
 
   return *this;
}

// other is the Graph we are copying from
// postcondition: 
//    the instance variables are initialized using other
Graph::Graph(const Graph& other) {
   
}

// destructor frees up the memory on the heap
Graph::~Graph() {

}

int Graph::pathLength(int from, int to) const {


}
