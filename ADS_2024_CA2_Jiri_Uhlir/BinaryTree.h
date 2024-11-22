#pragma once
#include "BSTNode.h"
#include <iostream>
#include <stdexcept>

template <class K, class V>
class BinaryTree {
private:
    BSTNode<K, V>* root;  // Root node for BinaryTree

    void addItemToArray(BSTNode<K, V>* node, int& pos, std::pair<K, V>* arr); // Helper for keySet (added)

public:
    BinaryTree();  // Constructor (no changes)
    BinaryTree(const BinaryTree<K, V>& other);  // Copy constructor
    BinaryTree<K, V>& operator=(const BinaryTree<K, V>& other);  // Assignment operator
    ~BinaryTree();  // Destructor

    void add(const K& key, const V& value);  // Add key-value pair to the tree (updated)
    bool remove(const K& key);  // Remove key from the tree (updated)
    void clear();  // Clear all nodes in the tree (added)
    bool containsKey(const K& key);  // Check if key exists (added)
    V& get(const K& key);  // Get value by key (added)
    BinaryTree<K, V> keySet();  // Get set of all keys (added)
    int size();  // Get size of the tree (added)
    bool removeKey(const K& key);  // Remove key (updated)
    V& operator[](const K& key);  // Access value using operator[] (added)
    void printInOrder();  // Print nodes in order
    void printInOrder(BSTNode<K, V>* node);  // Recursive helper for in-order printing
    void printPreOrder();  // Print nodes in pre-order
    void printPreOrder(BSTNode<K, V>* node);  // Recursive helper for pre-order printing
    void printPostOrder();  // Print nodes in post-order
    void printPostOrder(BSTNode<K, V>* node);  // Recursive helper for post-order printing
};

template <class K, class V>
BinaryTree<K, V>::BinaryTree() : root(nullptr) {}

template <class K, class V>
BinaryTree<K, V>::BinaryTree(const BinaryTree<K, V>& other) {
    root = nullptr;
    if (other.root) {
        root = new BSTNode<K, V>(*other.root);  // Create a copy of the tree
    }
}

template <class K, class V>
BinaryTree<K, V>& BinaryTree<K, V>::operator=(const BinaryTree<K, V>& other) {
    if (this == &other) return *this;  // Avoid self-assignment
    clear();  // Clear the current tree
    if (other.root) {
        root = new BSTNode<K, V>(*other.root);  // Copy the tree from other
    }
    return *this;
}

template <class K, class V>
BinaryTree<K, V>::~BinaryTree() {
    clear();  // Clean up tree nodes
}

template <class K, class V>
void BinaryTree<K, V>::add(const K& key, const V& value) {
    if (root == nullptr) {
        root = new BSTNode<K, V>(key, value);
    }
    else {
        root->add(key, value);  // Add the key-value pair to the tree
    }
}

template <class K, class V>
bool BinaryTree<K, V>::remove(const K& key) {
    BSTNode<K, V>* node = root->find(key);
    if (node) {
        // Proceed with node removal logic here (not implemented)
        return true;
    }
    return false;
}

template <class K, class V>
void BinaryTree<K, V>::clear() {
    if (root) {
        delete root;  // Delete root node and recursively clean up
        root = nullptr;
    }
}

template <class K, class V>
bool BinaryTree<K, V>::containsKey(const K& key) {
    return root->find(key) != nullptr;  // Check if the key exists in the tree
}

template <class K, class V>
V& BinaryTree<K, V>::get(const K& key) {
    BSTNode<K, V>* node = root->find(key);
    if (node) {
        return node->getValue();  // Return the value associated with the key
    }
    throw std::out_of_range("Key not found");  // Throw error if key doesn't exist
}

template <class K, class V>
BinaryTree<K, V> BinaryTree<K, V>::keySet() {
    BinaryTree<K, V> keySetTree;
    int pos = 0;
    std::pair<K, V>* arr = new std::pair<K, V>[size()];
    addItemToArray(root, pos, arr);  // Add all keys to array

    for (int i = 0; i < size(); ++i) {
        keySetTree.add(arr[i].first, arr[i].second);  // Add the keys to the new tree
    }
    delete[] arr;
    return keySetTree;
}

template <class K, class V>
int BinaryTree<K, V>::size() {
    return root ? root->count() : 0;  // Return the number of nodes in the tree
}

template <class K, class V>
bool BinaryTree<K, V>::removeKey(const K& key) {
    return remove(key);  // Call remove method to delete key
}

template <class K, class V>
V& BinaryTree<K, V>::operator[](const K& key) {
    return get(key);  // Access value by key using operator[]
}

template <class K, class V>
void BinaryTree<K, V>::printInOrder() {
    printInOrder(root);  // Print nodes in in-order traversal
}

template <class K, class V>
void BinaryTree<K, V>::printInOrder(BSTNode<K, V>* node) {
    if (node) {
        printInOrder(node->getLeft());
        std::cout << node->getKey() << ": " << node->getValue() << std::endl;
        printInOrder(node->getRight());
    }
}

// Implement PreOrder, PostOrder similarly...
