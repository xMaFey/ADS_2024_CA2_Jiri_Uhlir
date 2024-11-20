#include "Map.h"

template <class K, class V>
Map<K, V>::Map() {}

template <class K, class V>
void Map<K, V>::clear() {
    tree.clear();  // Uses BinaryTree's clear method to delete all nodes
}

template <class K, class V>
bool Map<K, V>::containsKey(K key) {
    try {
        get(key);  // If get doesn't throw, the key exists
        return true;
    }
    catch (const std::logic_error&) {
        return false;  // Key not found
    }
}

template <class K, class V>
V& Map<K, V>::get(K key) {
    for (auto& pair : tree) {  // Traverse through the tree and find the pair with matching key
        if (pair.first == key) {
            return pair.second;
        }
    }
    throw std::logic_error("Key not found");  // If key doesn't exist
}

template <class K, class V>
BinaryTree<K> Map<K, V>::keySet() {
    BinaryTree<K> keySetTree;
    // Traverse through the tree, extracting keys and adding them to a new BinaryTree
    for (auto& pair : tree) {
        keySetTree.add(pair.first);
    }
    return keySetTree;
}

template <class K, class V>
void Map<K, V>::put(K key, V value) {
    // Attempt to find the key in the map first
    if (containsKey(key)) {
        get(key) = value;  // Update value if key exists
    }
    else {
        tree.add(std::make_pair(key, value));  // Add new pair if key doesn't exist
    }
}

template <class K, class V>
int Map<K, V>::size() {
    return tree.count();  // Use BinaryTree's count method
}

template <class K, class V>
bool Map<K, V>::removeKey(K key) {
    for (auto& pair : tree) {
        if (pair.first == key) {
            tree.remove(pair);  // Remove the key-value pair from the tree
            return true;
        }
    }
    return false;  // Return false if key wasn't found
}

template <class K, class V>
V& Map<K, V>::operator[](K key) {
    if (containsKey(key)) {
        return get(key);  // Return the value if key exists
    }
    else {
        put(key, V());  // Insert the key with a default value if not found
        return get(key);  // Return the default value
    }
}
