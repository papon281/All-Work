#ifndef __HASHNODE__
#define __HASHNODE__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct HashNode {
    int RIN; // rin id of the voter
    int zipCode; // zip code
    char* lastName; // last name
    char* firstName; // first name
    bool castVote; // flag to track whether the voter casted a vote or not
    struct HashNode *next; // pointer to the next voter
};

/*
    Create a new node and return the value
*/
struct HashNode* createNode(int _RIN, char* _firstName, char* _lastName, int _zipCode){
    struct HashNode* node = (struct HashNode*) malloc(sizeof(struct HashNode));
    node->RIN = _RIN;
    node->firstName = (char*) malloc((strlen(_firstName)+1) * sizeof(char));
    strcpy(node->firstName, _firstName);
    node->lastName = (char*) malloc((strlen(_lastName)+1) * sizeof(char));
    strcpy(node->lastName, _lastName);
    node->zipCode = _zipCode;
    node->castVote = false;
    node->next = NULL;
    return node;
}

#endif //__HASHNODE__