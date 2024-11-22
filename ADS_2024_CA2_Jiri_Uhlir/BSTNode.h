#pragma once
#include <iostream>

template <class K, class V>
class BSTNode {
private:
    K key;      // Key of the node (added for key-value storage)
    V value;    // Value associated with the key (added for key-value storage)
    BSTNode<K, V>* parent;
    BSTNode<K, V>* left;
    BSTNode<K, V>* right;

public:
    // Constructors and Destructor
    BSTNode();
    BSTNode(const K& key, const V& value); // Constructor with key-value pair (added)
    BSTNode(const BSTNode<K, V>& other);    // Copy constructor
    ~BSTNode();

    // Assignment operator
    BSTNode<K, V>* operator=(const BSTNode<K, V>& other);

    // Getters and Setters (added methods to get/set both key and value)
    const K& getKey() const;                // Get the key of the node (added)
    const V& getValue() const;              // Get the value of the node (added)
    void setKey(const K& key);              // Set the key of the node (added)
    void setValue(const V& value);          // Set the value of the node (added)

    BSTNode<K, V>* getParent();             // Get the parent of the node (added)
    BSTNode<K, V>* getLeft();
    BSTNode<K, V>* getRight();
    void setLeft(BSTNode<K, V>* left);
    void setRight(BSTNode<K, V>* right);

    void add(const K& key, const V& value); // Add a key-value pair to the tree (updated for key-value)
    BSTNode<K, V>* find(const K& key);     // Find a node by key (updated for key-value)
    int count();                           // Count the number of nodes in the subtree
};

template <class K, class V>
BSTNode<K, V>::BSTNode() : parent(nullptr), left(nullptr), right(nullptr) {}

template <class K, class V>
BSTNode<K, V>::BSTNode(const K& key, const V& value) : key(key), value(value), parent(nullptr), left(nullptr), right(nullptr) {}

template <class K, class V>
BSTNode<K, V>::BSTNode(const BSTNode<K, V>& other) {
    key = other.key;
    value = other.value;
    parent = other.parent;
    if (other.left) left = new BSTNode<K, V>(*other.left);
    if (other.right) right = new BSTNode<K, V>(*other.right);
}

template <class K, class V>
BSTNode<K, V>* BSTNode<K, V>::operator=(const BSTNode<K, V>& other) {
    if (this == &other) return this;
    key = other.key;
    value = other.value;
    parent = other.parent;
    if (left) delete left;
    if (right) delete right;
    left = other.left ? new BSTNode<K, V>(*other.left) : nullptr;
    right = other.right ? new BSTNode<K, V>(*other.right) : nullptr;
    return this;
}

template <class K, class V>
BSTNode<K, V>::~BSTNode() {
    if (left) delete left;
    if (right) delete right;
}

template <class K, class V>
const K& BSTNode<K, V>::getKey() const {
    return key;  // Return the key
}

template <class K, class V>
const V& BSTNode<K, V>::getValue() const {
    return value;  // Return the value
}

template <class K, class V>
void BSTNode<K, V>::setKey(const K& key) {
    this->key = key;  // Set the key
}

template <class K, class V>
void BSTNode<K, V>::setValue(const V& value) {
    this->value = value;  // Set the value
}

template <class K, class V>
BSTNode<K, V>* BSTNode<K, V>::getParent() {
    return parent;  // Return the parent node
}

template <class K, class V>
BSTNode<K, V>* BSTNode<K, V>::getLeft() {
    return left;
}

template <class K, class V>
BSTNode<K, V>* BSTNode<K, V>::getRight() {
    return right;
}

template <class K, class V>
void BSTNode<K, V>::setLeft(BSTNode<K, V>* left) {
    this->left = left;
}

template <class K, class V>
void BSTNode<K, V>::setRight(BSTNode<K, V>* right) {
    this->right = right;
}

template <class K, class V>
void BSTNode<K, V>::add(const K& key, const V& value) {
    if (key < this->key) {
        if (left == nullptr) {
            left = new BSTNode<K, V>(key, value);
            left->parent = this;  // Set parent node
        }
        else {
            left->add(key, value);  // Recursive call to add the key-value pair
        }
    }
    else if (key > this->key) {
        if (right == nullptr) {
            right = new BSTNode<K, V>(key, value);
            right->parent = this;  // Set parent node
        }
        else {
            right->add(key, value);  // Recursive call to add the key-value pair
        }
    }
}

template <class K, class V>
BSTNode<K, V>* BSTNode<K, V>::find(const K& key) {
    if (key == this->key) return this;
    if (key < this->key) {
        return left ? left->find(key) : nullptr;  // Recursively search left
    }
    else {
        return right ? right->find(key) : nullptr;  // Recursively search right
    }
}

template <class K, class V>
int BSTNode<K, V>::count() {
    int c = 1;  // Count this node
    if (left) c += left->count();  // Count left subtree
    if (right) c += right->count();  // Count right subtree
    return c;
}
