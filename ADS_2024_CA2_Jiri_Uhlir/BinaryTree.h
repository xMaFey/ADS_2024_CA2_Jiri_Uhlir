#pragma once
#include "BSTNode.h"
#include <iostream>
#include <set>
#include <stdexcept>

template <class K, class V>
class BinaryTree {
private:
    BSTNode<K, V>* root;

    void addItemToArray(BSTNode<K, V>* node, int& pos, std::pair<K, V>* arr);
    void printInOrderHelper(BSTNode<K, V>* node);
    void printLettersHelper(BSTNode<K, V>* node); // Declare missing helper

public:
    BinaryTree();
    BinaryTree(const BinaryTree<K, V>& other);
    BinaryTree<K, V>& operator=(const BinaryTree<K, V>& other);
    ~BinaryTree();

    void add(const K& key, const V& value);
    bool remove(const K& key);
    void clear();
    bool containsKey(const K& key);
    V& get(const K& key);
    BinaryTree<K, V> keySet();
    int size();
    bool removeKey(const K& key);
    V& operator[](const K& key);
    void printInOrder();  // Print all nodes in in-order
    void printLetters();  // Print all letters for which words exist
    void printWordsForLetter(const K& letter); // Print words associated with a given letter
};

// Include implementation to handle templates
#include "BinaryTree.cpp"
