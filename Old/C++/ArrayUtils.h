#ifndef __ARRRAY_UTILS__
#define __ARRRAY_UTILS__

#include "Stack.h"
template<class T>
class ArrayUtils{
    public:
        static T* reverse(T* arr,int);
};

template<class T>
T* ArrayUtils<T>::reverse(T* arr,int len){
    Stack<T> st(len);
    for(int i = 0; i < len; i++){
        st.push(arr[i]);
    }
    for(int i = 0; i < len; i++){
        arr[i] = st.pop();
    }
    return arr;
}

#endif // __ARRRAY_UTILS
