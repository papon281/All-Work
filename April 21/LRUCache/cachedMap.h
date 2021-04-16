#include <iostream>
#include <utility>

template <typename KT, typename VT, template <typename KTS, typename VTS> typename Storage>
class CachedMap{
public:

    using value_type = std::pair<const KT,VT>;

    class iterator{
    public:
        iterator& operator++();
        iterator& operator*();
    };

    using end_iteraror = iterator;
    explicit CachedMap(std:: size_t mem_limit);
    iterator begin();
    iterator end();
    std::pair<iterator, bool> insert(const value_type & keyvalue);
    std::pair <iterator, bool> insert_or_assign(const value_type & keyvalue);
    iterator find(const KT & key);
private:
    Storage <KT, VT> storage_;
};

template <typename KTS, typename VTS>
class dumb_storage {
public:
    std::size_t size(const KTS & key) const;
    void write(const KTS & key, const VTS & value);
    std::tuple <bool, VTS> read(const KTS & key);
    std::tuple <bool, KTS> first_key();
    std::tuple <bool, KTS> next_key(const KTS & key);
    bool present (const KTS & key);
};
