// Student Name:

#include <iostream>
#include <limits> // for declaration of 'numeric_limits' for in
#include <ios>    // for declaration of 'streamsize' for in
#include "Graph.h"
#include <stdlib.h>
#include <queue>


using namespace std;

Graph::Graph()
{
    vertex = 0;
}

int Graph::numberOfVertices() const
{
    return vertex;
}

// get stream out of the fail state and clear the buffer
void Graph::clearClean(std::istream& in)
{
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// read the graph by first deleting the current graph
std::istream& operator >> (std::istream& in, Graph& graph)
{
    in >> graph.vertex;
    graph._array = new Node*[graph.vertex];
    for(int i = 0; i < graph.vertex; i++)
    {
        graph._array[i] = nullptr;
    }
    int u,v;
    while(in>>u)
    {
        in>>v;
        graph.addEdge(u,v);
    }
    return in;
}

Node* Graph:: getNewNode(int dest)
{
    Node* node = new Node;
    node -> dest = dest;
    node -> next= nullptr;
    return node;
}

void Graph::addEdge(int src, int dest)
{
    Node* newDest = getNewNode(dest);
    newDest->next = _array[src];
    _array[src] = newDest;


    Node* newSrc = getNewNode(src);
    newSrc->next = _array[dest];
    _array[dest] = newSrc;
}


std::ostream& operator << (std::ostream& out, const Graph& graph)
{
    for(int i = 0; i < graph.vertex; i++)
    {
        Node* cursor = graph._array[i];
        while(cursor)
        {
            if(i < cursor->dest)
            {
                out<<i<<" "<<cursor->dest<<std::endl;
            }
            cursor = cursor->next;
        }
    }
    return out;
}

void Graph :: traverse(int source, bool* visited) const
{
    visited[source] = true;
    std::queue<int> que;
    que.push(source);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        Node* cursor = _array[u];
        while(cursor)
        {
            if(!visited[cursor->dest])
            {
                visited[cursor->dest] =  true;
                que.push(cursor->dest);
            }
            cursor = cursor->next;
        }
    }
}

bool Graph :: isConnected() const
{
    bool *visited = new bool[vertex];
    for(int i = 0; i < vertex; i++)
    {
        visited[i] = false;
    }

    traverse(0, visited);
    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }
    return true;

}

bool Graph :: isCyclicUtil(int v, bool* visited, int parent ) const
{
    visited[v] = true;
    Node* cursor = _array[v];
    while(cursor)
    {
        if(!visited[cursor->dest])
        {
            if(isCyclicUtil(cursor->dest,visited,v))
            {
                return true;
            }
        }
        else if(cursor->dest != parent)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

bool Graph :: hasCycle() const
{
    bool *visited = new bool[vertex];
    for (int i = 0; i< vertex; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < vertex; i++)
    {
        if(!visited[i])
            if(isCyclicUtil(i, visited, -1))
                return true;
    }
    return false;
}

void Graph :: printComponents(int src, bool* visited) const
{
    visited[src] = true;
    std::cout << src << " ";
    Node* cursor = _array[src];
    while(cursor)
    {
        if(!visited[cursor->dest])
        {
            printComponents(cursor->dest, visited);
        }
        cursor = cursor->next;
    }
}

void Graph::listComponents(std::ostream& out) const
{
    bool* visited = new bool[vertex];

    for(int i = 0; i < vertex; i++)
    {
        visited[i] = false;
    }

    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i])
        {
            printComponents(i,visited);
            out << std::endl;
        }
    }
}

void Graph :: deleteNode()
{
    for(int i = 0; i < vertex; i++)
    {
        Node* cursor = _array[i];
        while(cursor)
        {
            Node* tmp = cursor;
            cursor = cursor->next;
            delete tmp;
        }
    }
    delete[] _array;
}

// postcondition:
//    deep copy of the rtSide was made
Graph& Graph::operator = (const Graph& rtSide)
{
    deleteNode();
    for(int i = 0; i < rtSide.vertex; i++){
        _array[i] = nullptr;
    }
    for(int i = 0; i < rtSide.vertex; i++)
    {
        Node* cursor = _array[i];
        while(cursor)
        {
            addEdge(i, cursor->dest);
        }
        cursor = cursor->next;
    }
    return *this;
}

// other is the Graph we are copying from
// postcondition:
//    the instance variables are initialized using other
Graph::Graph(const Graph& other)
{
    vertex = other.vertex;
    for(int i = 0; i < vertex; i++){
        _array[i] = nullptr;
    }
    for(int i = 0; i < vertex; i++)
    {
        Node* cursor = other._array[i];
        while(cursor)
        {
            addEdge(i,cursor->dest);
            cursor = cursor->next;
        }
    }

}

// destructor frees up the memory on the heap
Graph::~Graph()
{
    deleteNode();
}

int Graph :: countLength(int source, int destination) const
{
    bool* visited = new bool[vertex];
    int* distance = new int[vertex];
    for(int i = 0; i < vertex; i++)
    {
        visited[i] = false;
        distance[i] = 0;
    }
    queue<int> que;
    distance[source] = 0;
    que.push(source);
    visited[source] = true;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        Node* cursor = _array[u];
        while(cursor)
        {
            if(!visited[cursor->dest])
            {
                distance[cursor->dest] = distance[u] + 1;
                que.push(cursor->dest);
                visited[cursor->dest] = true;
            }
            cursor = cursor->next;
        }
    }
    return distance[destination];
}

bool Graph :: findPath(int source, int destination, bool* visited) const
{
    visited[source] = true;
    std::queue<int> que;
    que.push(source);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        if(u == destination)
        {
            return true;
        }
        Node* cursor = _array[u];
        while(cursor)
        {
            if(!visited[cursor->dest])
            {
                visited[cursor->dest] =  true;
                que.push(cursor->dest);
            }
            cursor = cursor->next;
        }
    }
    return false;
}

int Graph::pathLength(int from, int to) const
{
    int cnt = 0;
    bool* visited = new bool[vertex];
    for(int i = 0; i < vertex; i++)
    {
        visited[i] = false;
    }
    if(from < 0 || from > vertex || to < 0 || to > vertex)
    {
        return -1;
    }
    else if(from == to)
    {
        return 0;
    }
    else if(!findPath(from,to,visited))
    {
        return -1;
    }
    else
    {
        return countLength(from,to);
    }
}
