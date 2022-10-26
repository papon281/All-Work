// Student Name:
//
// Represents a univariate polynomial with a binary search tree
// Course: CPSC 2150
#ifndef UNIVARIATE_H
#define UNIVARIATE_H

#include <iostream>    // std::ostream
#include <functional>  // std::function
#include "Term.h"

class Univariate {
   public :
      // create the zero polynomial
      // set the comparison function to cmp
      Univariate(std::function<bool(int, int)> cmp);
      // create a monomial with one term c x^d
      // and set the comparison function between 2 term degrees
      Univariate(int c, int d, std::function<bool(int, int)> cmp);
      // return the highest degree of the polynomial
      // in the special case of the zero polynomial return -1
      int degree() const;
      // return the coefficient of term that has degree n
      int coefficient(int n) const;
      // evaluate the polynomial with the given value of x
      double evaluate(double x) const;
      // determine if the polynomial is the zero polynomial
      bool isZeroPolynomial() const;
      // insert an already created term into the polynomial
      // precondition: t is not the nullptr
      // let d be the degree of a node's term, and let g be the degree of the argument term t
      // if d is equal to g, then deal accordingly otherwise use the comparison function
      // if cmp(d, g) is true, then insert the term t into the left subtree of the node
      // if cmp(d, g) is false, then insert the term t into the right subtree of the node
      void insert(Term* t);
      // return the number of terms in the polynomial:
      // for the zero polynomial return 1
      int numberOfTerms() const;
      // add (sum) two polynomials and return a new polynomial which is the sum
      const Univariate operator + (const Univariate& b);
      // differentiate this polynomial and return a new polynomial
      const Univariate differentiate() const;

      // copy constructor
      Univariate(const Univariate&);
      // destructor
      ~Univariate();
      // overloaded assignment operator
      Univariate& operator = (const Univariate&);

      // output the polynomial nicely in x
      friend std::ostream& operator << (std::ostream&, const Univariate&);
      // first read the number of terms n (as an int)
      // followed by the pairs of coefficient and degree
      // for each of the n terms
      friend std::istream& operator >> (std::istream&, Univariate&);

    private:
      // a Binary Search Tree Node
      // Each Node stores the pointer to a term and links to its children.
      // Terms are stored in the tree in the order depending on cmpFct order.
      //
      // Note:
      //     No duplicate terms i.e. terms with the same degree will be in the tree

      // You can make the Node a class of its own if you prefer but the
      // Node must have a pointer to a term and a pointer to each child
      struct Node {
          Node *left;
          Term *term;
          Node *right;
      };

      // the BST is always sorted and never has duplicates
      std::function<bool(int,int)> cmpFct;
      Node* root;

};
#endif

