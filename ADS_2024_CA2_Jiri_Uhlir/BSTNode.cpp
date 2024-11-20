#include "BSTNode.h"  // Include BSTNode header file

// Default constructor for BSTNode
template <class T>
BSTNode<T>::BSTNode() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

// Constructor with data
template <class T>
BSTNode<T>::BSTNode(T data) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    this->data = data;  // Set the node's data
}

// Copy constructor
template <class T>
BSTNode<T>::BSTNode(const BSTNode<T>& other) {
    left = right = nullptr;  // Initialize pointers to nullptr
    if (other.left != nullptr) {
        this->left = new BSTNode<T>(*other.left);  // Deep copy left node
    }
    if (other.right != nullptr) {
        this->right = new BSTNode<T>(*other.right);  // Deep copy right node
    }
}

// Assignment operator
template <class T>
BSTNode<T>* BSTNode<T>::operator=(const BSTNode<T>& other) {
    if (this == &other) {
        return *this;  // Avoid self-assignment
    }
    delete left;
    delete right;

    if (other.left != nullptr) {
        this->left = new BSTNode<T>(*other.left);  // Deep copy left node
    }
    if (other.right != nullptr) {
        this->right = new BSTNode<T>(*other.right);  // Deep copy right node
    }
    return *this;
}

// Destructor
template <class T>
BSTNode<T>::~BSTNode() {
    delete left;  // Delete left subtree
    delete right;  // Delete right subtree
}

// Getter and setter functions for data, left, right, and parent pointers
template <class T>
T& BSTNode<T>::getItem() {
    return data;  // Return the data of the node
}

template <class T>
void BSTNode<T>::setItem(T item) {
    this->data = item;  // Set the data of the node
}

template <class T>
BSTNode<T>* BSTNode<T>::getLeft() {
    return left;  // Return the left child
}

template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* left) {
    this->left = left;  // Set the left child
}

template <class T>
BSTNode<T>* BSTNode<T>::getRight() {
    return right;  // Return the right child
}

template <class T>
void BSTNode<T>::setRight(BSTNode<T>* right) {
    this->right = right;  // Set the right child
}

template <class T>
BSTNode<T>* BSTNode<T>::getParent() {
    return parent;  // Return the parent node
}

template <class T>
void BSTNode<T>::setParent(BSTNode<T>* parent) {
    this->parent = parent;  // Set the parent node
}
