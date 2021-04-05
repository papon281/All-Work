#include "ArrayUtils.h"
#include "stack.h"
using namespace std;

template<class T>
T* ArrayUtils<T>::Reverse(T* arr,int len){
    Stack<T> st(len);
    for(int i = 0; i < len; i++){
        st.push(arr[i]);
    }
    for(int i = 0; i < len; i++){
        arr[i] = st.pop();
    }
    return arr;
}
