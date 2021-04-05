#ifndef __SORT__
#define __SORT__

#include "Pair.h"

void sortHelper(struct Pair* data[], int lo, int hi){
    if (lo < hi){
        int mid = (lo + hi)/2;
        sortHelper(data, lo, mid);
        sortHelper(data, mid+1, hi);
        struct Pair** temp = (struct Pair**)malloc((hi-lo+1)*sizeof(struct Pair*));
        int i = 0, j = mid+1, k = 0;
        while( i <= mid && j <= hi){
            if(data[i]->voteCount >= data[j]->voteCount){
                temp[k++] = data[i++];
            } else {
                temp[k++] = data[j++];
            }
        }
        while(i <= mid) temp[k++] = data[i++];
        while(j <= hi) temp[k++] = data[j++];
        j = 0;
        for(i = lo; i <= hi; i++){
            data[i] = temp[j++];
        }
    }
}

void sort(struct Pair* data[], int n){
    sortHelper(data, 0, n-1);
}
#endif //__SORT__