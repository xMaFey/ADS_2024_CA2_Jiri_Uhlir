#pragma once
#include "BinaryTree.h"
#include <stdexcept>
#include <optional>

template <class K, class V>
class Map {
private:
    BinaryTree<std::pair<K, V>> tree;  // The underlying BinaryTree for storing key-value pairs

public:
    Map();
    void clear();
    bool containsKey(K key);
    V& get(K key);
    BinaryTree<K> keySet();
    void put(K key, V value);
    int size();
    bool removeKey(K key);
    V& operator[](K key);
};
#pragma once
