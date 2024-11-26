#pragma once
#include "BinaryTree.h" // Include BinaryTree for the tree structure

template <class K, class V> // Define template classes for Key (K) and Value (V)
class TreeMap
{
private:
    BinaryTree<std::pair<K, V>> tree;  // Internal tree holding key-value pairs

public:
    // Clears the map by clearing the internal BinaryTree
    void clear() {
        tree.clear();  // Uses the clear method from BinaryTree class
    }

    // Checks if the map contains a specified key
    bool containsKey(K key) {
        try {
            get(key);  // Try to get the value for the key
            return true;  // If no exception, key is found
        }
        catch (...) {
            return false;  // If exception occurs, key is not found
        }
    }

    // Returns the value associated with the specified key
    V& get(K key) {
        std::pair<K, V> pairToFind = std::make_pair(key, V());  // Create a pair with the key and a default value
        return tree.get(pairToFind).second;  // Get the pair and return the value (second element of the pair)
    }

    // Returns a BinaryTree containing all the keys
    BinaryTree<K> keySet() {
        BinaryTree<K> keys;  // Create a BinaryTree to hold the keys
        // Traverse the internal tree and add each key to the keys tree
        for (auto item : tree.toArray()) {
            keys.add(item.first);  // Add each key (first element of the pair)
        }
        return keys;
    }

    // Inserts a new key-value pair into the map
    void put(K key, V value) {
        std::pair<K, V> pairToInsert = std::make_pair(key, value);  // Create a pair of key and value
        tree.add(pairToInsert);  // Add the pair to the BinaryTree
    }

    // Returns the number of key-value mappings in the map
    int size() {
        return tree.count();  // Get the count of items in the internal BinaryTree
    }

    // Removes the entry associated with the given key
    bool removeKey(K key) {
        std::pair<K, V> pairToRemove = std::make_pair(key, V());  // Create the pair with the key
        return tree.remove(pairToRemove);  // Call the remove method of BinaryTree to remove the pair
    }

    // Overload the operator[] to access the value for a specific key
    V& operator[](K key) {
        return get(key);  // Access the value for the key using the get method
    }
};
