// Student Name:

// Represents a univariate polynomial with a binary search tree
// Course: CPSC 2150

#include <iostream>
#include <functional>   // std::function
#include <stdlib.h>
#include <cmath>

#include "Term.h"
#include "Univariate.h"

using namespace std;


// create the zero polynomial
Univariate::Univariate(std::function<bool(int, int)> fct): cmpFct(fct)
{
    root = nullptr;
}

// precondition:
//    c is the coefficient of the only term in the polynomial
//    d is the degree of the only term in the polynomial
// postcondition:
//    a Univariate with one term c x^d is created
Univariate::Univariate(int c, int d, std::function<bool(int, int)> fct) : cmpFct(fct)
{
    Term* term = new Term(c,d);
    insert(term);

}

// precondition:
//    p is the Univariate we are copying from
// postcondition:
//    a Univariate which is a copy of p is created
Univariate::Univariate(const Univariate& p)
{
  root = nullptr;
  cmpFct = p.cmpFct;
  int mx = p.degree();
  for(int i = 0; i <= mx; i++){
    int c = p.coefficient(i);
    insert(new Term(c, i));
  }
}

// postcondition:
//    returns the highest degree of the polynomial
//    in the special case of the zero polynomial, return -1
int Univariate::degree() const
{
    if(isZeroPolynomial())
    {
        return -1;
    }
    Node* cursor = root;
    while(cursor->right){
      cursor = cursor->right;
    }
    return cursor->term->getDegree();
}

// postcondition:
//    returns the coefficient of term that has degree n
int Univariate::coefficient(int n) const
{
    Node* current = root;
    while(current){
      if(current->term->getDegree() == n){
        return current->term->getCoeff();
      }
      if(n < current->term->getDegree()){
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return 0;
}

// postcondition:
//    returns the value of evaluating the polynomial at x

double Univariate::evaluate(double x) const{
  double res = 0.0;
  int mx = degree();
  for(int i = 0; i <= mx; i++){
    int c = coefficient(i);
    res = res + c * pow(x,i);
  }
  return res;
}

// determine if the polynomial is the zero polynomial
bool Univariate::isZeroPolynomial() const
{
  return (root == nullptr);
}

// precondition:
//   the term pointed to by t has been allocated
//   t != nullptr
// postcondition:
//
void Univariate::insert(Term* t)
{
    if(t == nullptr)
    {
        return;
    }
    Node* newNode = new Node();
    newNode->term = t;
    newNode->left = nullptr;
    newNode->right = nullptr;

    Node* current = root;

    if(root == nullptr)
    {
        root = newNode;
        return;
    }

    while(current != nullptr)
    {
        if(t->getDegree() < current->term->getDegree())
        {
            if(current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else if(t->getDegree() > current->term->getDegree())
        {
            if(current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            current = current->right;
        }
    }
}

// postcondition:
//    returns the number of terms in the tree
//    in the special case of the zero polynomial return 1

int Univariate::numberOfTerms() const
{
   int mx = degree();
   int cnt = 0;
   for(int i = 0; i <= mx; i++){
      if(coefficient(i) != 0){
         cnt++;
      }
   }
   return cnt;
}

// precondition:
//    a and b are the two polynomials to sum up,
// postcondition:
//    create a new polynomial which is the sum of two given polynomials
//    only the non-zero terms will be stored in the sum polynomial

const Univariate Univariate::operator + (const Univariate& b)
{
  Univariate result(cmpFct);
  int maxDegreeOfCurrent = degree();
  int maxDegreeOfOther = b.degree();
  int m = max(maxDegreeOfCurrent, maxDegreeOfOther);
  for(int i = 0; i <= m; i++){
    int co = coefficient(i) + b.coefficient(i);
    if(co != 0){
      result.insert(new Term(co, i));
    }
  }
  return result;
}


// differentiate
// postcondition:
//    returns a new polynomial
const Univariate Univariate::differentiate() const
{
    Univariate result(cmpFct);
    int mx = degree();
    for(int i = 1; i <= mx; i++){
      int c = coefficient(i);
      if(c != 0){
        result.insert(new Term(c * i, i-1));
      }
    }
    return result;
}

void Univariate::clean(Node* node){
  if(node == nullptr) return;
  clean(node->left);
  clean(node->right);
  delete node->term;
  delete node;
}
// destructor frees up the memory
Univariate::~Univariate()
{
    clean(root);
}

// postcondition:
//    deep copy of the rtSide was made
Univariate& Univariate::operator = (const Univariate& rtSide)
{
  clean(root);
  root = nullptr;
  cmpFct = rtSide.cmpFct;
  int mx = rtSide.degree();
  for(int i = 0; i <= mx; i++){
    int c = rtSide.coefficient(i);
    insert(new Term(c, i));
  }
  return *this;
}

// postcondition:
//    if non numeric input is given, the istream enters a fail state
//    only non-zero terms will be inserted into the polynomial
std::istream& operator >> (std::istream& in, Univariate& poly)
{
    int n;
    // input the number of non-zero terms n of the polynomial: ";
    in >> n;
    //get the degree and coefficient of every term
    int c,d;
    for (int i = 0; i < n; i++)
    {
        in >> c >> d;
        poly.insert(new Term(c,d));
    }
    return in;
}

// postcondition:
//    outputs the polynomial, starting with the highest degree
std::ostream& operator << (std::ostream& out, const Univariate& p)
{
    int mx = p.degree();
    bool isFirst = true;
    for(int i = mx; i >= 0; i--){
      int c = p.coefficient(i);
      if(c != 0){
        if(c > 0 && !isFirst) out<<"+";
        out<<c;
        if(i > 0){
           out<<"x";
           if(i > 1) out<<"^"<<i;
        }
        isFirst = false;
      }
    }
    return out;
}
