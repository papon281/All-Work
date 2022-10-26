//submit this file
//you do NOT need to include any header in this file
//just write your BST implementation here right away

using namespace std;

template <typename T>
BST<T>::BST(const BST &another)
{ // TODO: according to header

}

template <typename T>
bool BST<T>::isEmpty() const
{ // TODO: according to header
    if(root==nullptr){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
bool BST<T>::add(string key, T value)
{ // TODO: according to header
}

template <typename T>
bool BST<T>::remove(string key)
{ // TODO: according to header
}

template <typename T>
T *BST<T>::get(string key) const
{ // TODO: according to header
}

template <typename T>
void BST<T>::getBetweenRangeHelper(const BST<T> *current_bst, string start, string end, list<T> *resultList) const
{ // TODO: according to header
}

template <typename T>
const BST<T> *BST<T>::findMin() const
{ // TODO: according to header
}
