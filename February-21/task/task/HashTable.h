#ifndef __HASHTABLE__
#define __HASHTABLE__
#include "HashNode.h"
#include "Sort.h"

struct HashTable{
    struct HashNode** rinTable; // hashtable against key rin
    int voterCountByZip[10000]; // count casted vote for each zip code
    int capacity; // capacity of the hash table
};

/*
    Create a new Hash table of provided capacity
*/
struct HashTable* createNewTable(int _capacity) {
    // initiate a hash table
    struct HashTable* table = (struct HashTable*) malloc(sizeof(struct HashTable));
    // set the capacity
    table->capacity = _capacity;
    // initiate the array of hash node
    table->rinTable = (struct HashNode**) malloc(table->capacity * sizeof(struct HashNode*));
    for (int i = 0; i < table->capacity; i++){
        // set default value of each hashnode to null
        table->rinTable[i] = NULL;
    }
    for(int i = 0; i < 10000; i++){
        // voters of a zipcode who casted vote is 0 initially
        table->voterCountByZip[i] = 0;
    }
    return table;
}

int hash(struct HashTable* table, int RIN) {
    return RIN % table->capacity;
}

/*
    Search for entry agains rin
    Return NULL if not found
*/
struct HashNode* find(struct HashTable *table, int residentid){
    // get the hash value
    int hashVal = hash(table, residentid);
    // extract the head of the linked list
    struct HashNode* entry = table->rinTable[hashVal];
    while (entry != NULL) { // iterate until the mathc found or end of the list
        if (entry->RIN == residentid) {
            // match found. return the node
            return entry;
        }
        entry = entry->next;
    }
    // reached at the end of the list. return null
    return NULL;
}

/*
    Add new elements in the hashtable
    If the rin exist, nothing happen
*/
 
void insert(struct HashTable* table, int RIN, char* firstName, char* lastName,int zipCode){
    if(find(table, RIN) != NULL){
        // if rin is found, no need to proceed.
        return;
    }
    // get the hashvalue
    int hashVal = hash(table, RIN);
    // create a hashnode
    struct HashNode *newNode = createNode(RIN, firstName,lastName,zipCode);
    // Add newnode at the head of the linked list
    newNode->next = table->rinTable[hashVal];
    // mark newnode as new head
    table->rinTable[hashVal] = newNode;
}

/*
    Remove an entry from hash table
    if rin does not exis, an error message is displayed
*/
void removeFromTable(struct HashTable* table, int RIN){
    // get the hashvalue
    int hashVal = hash(table, RIN);
    // get the head of the linked list
    struct HashNode* entry = table->rinTable[hashVal];
    // track previous node of current node
    struct HashNode *prev = NULL;
    while(entry!=NULL){
        if(entry->RIN == RIN){
            // match found
            if(prev == NULL){
                // current node is the head of the linked list
                // set the next of current node of current head as new head
                table->rinTable[hashVal] = entry->next;
            } else {
                // connect previous and next node of current node
                prev->next = entry->next;
            }
            if(entry->castVote){
                // decrement the counter of curernt zipcode who casted vote
                table->voterCountByZip[entry->zipCode]--;
            }
            // free the current node
            free(entry);
            break;
        }
        // set current node as previous node
        prev = entry;
        entry = entry->next;
    }
    if(entry == NULL){
        printf("Resident id number not found or deleted before\n");
    }
    else{
        // set it to null
        entry = NULL;
        printf("Resident id number deleted\n");
    }
}

/*
    Search for an entry against a rin in the hashtable
    An error message is displayed if not found
*/
void search(struct HashTable *table, int residentid) {
    // find for the node
    struct HashNode* entry = find(table, residentid);
    if (entry != NULL) {
        // entry found
        printf("%d %s %s %d\n", entry->RIN, entry->lastName, entry->firstName, entry->zipCode);
    } else {
        // entry is not found
        printf("No Element Found\n");
    }
}

/*
    Registers a voter
    If already registered or not present, return false
    Otherwise, return true
*/
bool registeredVoter(struct HashTable* table, int residentId){
    // get the hash value
    int hashVal = hash(table, residentId);
    // find the entry in the linked list
    struct HashNode* entry = find(table, residentId);
    if(entry == NULL){
        // no entry is found
        return false;
    }
    if(entry->castVote == false){
        // this resident didn't cast vote yet
        // cast the vote
        entry->castVote = true;
        // increment the counter of corresponding zipcode
        table->voterCountByZip[entry->zipCode]++;
        return true;
    } else {
        // already casted vote
        return false;
    }
}

/*
    Bulk register from a file
    The file should contains space separated integers
*/
void bulkRegister(struct HashTable *table, char* filename) {
    // create file pointer to read from file
    FILE *file = fopen(filename, "r");
    int rin;
    while(fscanf(file, "%d",&rin) != EOF){
        // register each rin
        registeredVoter(table, rin);
    }
}

/*
    Count total vote casted
    Iterate over all the entry of hashtable and count number of vote casted
*/

int countTotalVoteCasted(struct HashTable *table) {
    struct HashNode* entry = NULL;
    int count = 0;
    for(int i =0; i<table->capacity; i++) {
        entry = table->rinTable[i];
        while(entry!=NULL) {
            if(entry->castVote == true) {
                count++;
            }
            entry = entry->next;
        }
    }
    return count;
}

/*
    Calculate vote cast percentage against total voter
*/
float calculatePercentage(struct HashTable *table){
    int voteCasted = countTotalVoteCasted(table);
    float percentage = (float)((100.0 * voteCasted)/table->capacity);
    return percentage;
}

/*
    display all the voters rin who casted a vote
    Iterate over all the entry and display rin of the voter
    who resides in certain zipCode and casted vote
*/
void printParticipantId(struct HashTable *table, int zipCode){
    struct HashNode* entry = NULL;
    bool found = false;
    printf("Total vote: %d\n", countTotalVoteCasted(table));
    for(int i =0; i<table->capacity; i++) {
        entry = table->rinTable[i];
        while(entry != NULL){
            if(entry->zipCode == zipCode && entry->castVote == true) {
                printf("%d\n",entry->RIN);
                found = true;
            }
            entry = entry->next;
        }
    }
    if(!found) {
        printf("There is no voters in this zip-code who caste vote\n");
    }
}

/*
    count voter of a zip code who casted vote
*/
int countVoter(struct HashTable* table, int zipCode) {
    return table->voterCountByZip[zipCode];
}

/*
    display vote cast count in decreasing order against zip codes
*/
void printZipCode(struct HashTable *table) {
    int cnt = 0;
    // count number of zipcode whose residents casted vote
    for(int i = 0; i < 10000; i++){
        if(table->voterCountByZip[i] > 0) cnt++;
    }
    // initiate an array
    struct Pair** data = (struct Pair**) malloc((cnt+1) * sizeof(struct Pair*));
    int k = 0;
    // populate the array with zipcode and casted vote counter
    for(int i = 0; i < 10000; i++){
        if(table->voterCountByZip[i] > 0){
            data[k++] = createPair(i, table->voterCountByZip[i]);
        }
    }
    // sort the data in decreasing order based on vote casted
    sort(data, cnt);
    // display the data
    for(int i = 0; i < cnt; i++){
        printf("%d %d\n", data[i]->zipCode, data[i]->voteCount);
    }
}
#endif //__HASHTABLE__