#include "set.h"
#include "node.h"

int Set::Node::count_nodes = 0;  // initialize total number of existing nodes to zero

/*****************************************************
 * Implementation of the member functions             *
 ******************************************************/

// Used for debug purposes
// Return number of existing nodes  -- static member function
int Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

// Default constructor
Set::Set() : counter{0} {
    // IMPLEMENT before Lab1 HA
}

// Conversion constructor
Set::Set(int n)
    : Set{}  // create an empty list
{
    // IMPLEMENT before Lab1 HA
}

// Constructor to create a Set from a sorted vector v
Set::Set(const std::vector<int>& v)
    : Set{}  // create an empty list
{
    // IMPLEMENT before Lab1 HA
    Node* node = head;
    for(int i = 0; i < v.size(); i++){
        _insert(node, v[i]);
    }
}

// Make the set empty
void Set::make_empty() {
    // IMPLEMENT before Lab1 HA
    Set::Node* node = head;
    while(node){
        Node* temp = node;
        node = node->next;
        delete temp;
    }
    delete node;
}

Set::~Set() {
    // Member function make_empty() can be used to implement the destructor
    // IMPLEMENT before Lab1 HA
    make_empty();
}

// Copy constructor
Set::Set(const Set& source)
    : Set{}  // create an empty list
{
    // IMPLEMENT before Lab1 HA
    Set::Node* node = head;
    Set::Node* temp{source.head->next};
    while(temp != source.tail){
        _insert(node, temp->value);
        temp = temp -> next;
    }
}

// Copy-and-swap assignment operator
Set& Set::operator=(Set source) {
    // IMPLEMENT before Lab1 HA
    Set::Node* node = head;
    Set:Node* temp(source.head->next);
    while(temp != source.tail){
        _insert(node,temp->value);
        temp = temp->next;
    }
    return *this;
}

// Test set membership
bool Set::is_member(int val) const {
    // IMPLEMENT before Lab1 HA
    Set::Node* node = head;
    while(node){
        if(node->value == val){
            return true;
        }
        node = node->next;
    }
    return false;  // remove this line
}

// Test whether a set is empty
bool Set::is_empty() const {
    return (counter == 0);
}


// Return number of elements in the set
size_t Set::cardinality() const {
    return counter;
}


// Modify *this such that it becomes the union of *this with Set S
// Add to *this all elements in Set S (repeated elements are not allowed)
Set& Set::operator+=(const Set& S) {
    // IMPLEMENT
   if(S.is_empty()){
        return *this;
    }
    else{
         Set::Node* node{S.head->next};
    }
    while(node != S.tail){
        if(!is_member(node->value))
            _insert(node, temp->value);
        temp = temp->next;
    }
    return *this;
}

// Modify *this such that it becomes the intersection of *this with Set S
Set& Set::operator*=(const Set& S) {
    // IMPLEMENT
    if(S.is_empty()){
        return *this;
    }
    else{
         Set::Node* node{S.head->next};
    }
    while(node != S.tail){
        if(!is_member(node -> value)){
            _remove(node);
        }
        node = node -> next;
    }
    return *this;
}

// Modify *this such that it becomes the Set difference between Set *this and Set S
Set& Set::operator-=(const Set& S) {
    // IMPLEMENT
    if(S.is_empty()){
        return *this;
    }
    else{
         Set::Node* node{S.head->next};
    }

    while(node != S.tail){
        if(is_member(node->value)){
            _remove(node);
        }
        node = node->next;
    }
    return *this;
}

// Overloaded stream insertion operator<<
std::ostream& operator<<(std::ostream& os, const Set& b) {
    if (b.is_empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* temp{b.head->next};

        os << "{ ";
        while (temp != b.tail) {
            os << temp->value << " ";
            temp = temp->next;
        }
        os << "}";
    }
    return os;
}

/* ******************************************** *
 * Private Member Functions -- Implementation   *
 * ******************************************** */

//If you add any private member functions to class Set then write the implementation here

// Insert a new Node storing val after the Node pointed by p
void Set::_insert(Node* p, int val) {
    // IMPLEMENT
    Set::Node* node = new Node();
    node->value = val;
    node->next = p;
    p = node;
    node->count_nodes++;
}


// Remove the Node pointed by p
void Set::_remove(Node* p) {
    // IMPLEMENT
    Set::Node* current = p;
    Set:Node* next = nullptr;
    while(current != nullptr){
        next = current->next;
        delete(current);
        current = next;
    }
    p = nullptr;
}


