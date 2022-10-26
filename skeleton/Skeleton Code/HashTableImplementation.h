//submit this file
//you do NOT need to include any header in this file
//just write your HashTable implementation here right away

template <typename K, typename T>
HashTable<K,T>::HashTable(int m, int (*h)(K), int (*h2)(int), Mode mode, double loadLimit, bool isReferenceOnly)
    : m(m), h(h), h2(h2), mode(mode), loadLimit(loadLimit),isReferenceOnly(isReferenceOnly)
{ // TODO: according to header
}


template <typename K, typename T>
HashTable<K,T>::~HashTable()
{ // TODO: according to header
}

template <typename K, typename T>
HashTable<K,T>::HashTable(const HashTable& another)
{ // TODO: according to header
}

template <typename K, typename T>
void HashTable<K,T>::operator=(const HashTable& another)
{ // TODO: according to header
}

template <typename K, typename T>
int HashTable<K,T>::add(K key, T* data)
{ // TODO: according to header
}


template <typename K, typename T>
bool HashTable<K,T>::remove(K key)
{ // TODO: according to header
}


template <typename K, typename T>
T* HashTable<K,T>::get(K key) const
{ // TODO: according to header
}
