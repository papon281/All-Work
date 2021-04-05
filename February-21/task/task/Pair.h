#ifndef __PAIR__
#define __PAIR__

struct Pair{
    int zipCode;
    int voteCount;
};

struct Pair* createPair(int _zipCode,  int _voteCount){
    struct Pair* pair = (struct Pair*) malloc(sizeof(struct Pair));
    pair->zipCode = _zipCode;
    pair->voteCount = _voteCount;
    return pair;
}
#endif //__PAIR__