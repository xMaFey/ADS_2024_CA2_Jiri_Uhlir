#include "BSTNode.h"

template <class K, class V>
BSTNode<K, V>::BSTNode() : parent(nullptr), left(nullptr), right(nullptr) {}

template <class K, class V>
BSTNode<K, V>::BSTNode(const K& key, const V& value) : key(key), value(value), parent(nullptr), left(nullptr), right(nullptr) {}

template <class K, class V>
BSTNode<K, V>::BSTNode(const BSTNode<K, V>& other) {
    key = other.key;
    value = other.value;
    parent = other.parent;
    left = other.left ? new BSTNode<K, V>(*other.left) : nullptr;
    right = other.right ? new BSTNode<K, V>(*other.right) : nullptr;
}

template <class K, class V>
BSTNode<K, V>* BSTNode<K, V>::operator=(const BSTNode<K, V>& other) {
    if (this == &other) return this;
    key = other.key;
    value = other.value;
    parent = other.parent;
    left = other.left ? new BSTNode<K, V>(*other.left) : nullptr;
    right = other.right ? new BSTNode<K, V>(*other.right) : nullptr;
    return this;
}

template <class K, class V>
BSTNode<K, V>::~BSTNode() {
    delete left;
    delete right;
}

template <class K, class V>
const K& BSTNode<K, V>::getKey() const {
    return key;
}

template <class K, class V>
const V& BSTNode<K, V>::getValue() const {
    return value;
}

template <class K, class V>
void BSTNode<K, V>::setKey(const K& key) {
    this->key = key;
}

template <class K, class V>
void BSTNode<K, V>::setValue(const V& value) {
    this->value = value;
}

template <class K, class V>
BSTNode<K, V>* BSTNode<K, V>::getParent() {
    return parent;
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
            left->parent = this;
        }
        else {
            left->add(key, value);
        }
    }
    else if (key > this->key) {
        if (right == nullptr) {
            right = new BSTNode<K, V>(key, value);
            right->parent = this;
        }
        else {
            right->add(key, value);
        }
    }
}

template <class K, class V>
BSTNode<K, V>* BSTNode<K, V>::find(const K& key) {
    if (key == this->key) return this;
    if (key < this->key) {
        return left ? left->find(key) : nullptr;
    }
    else {
        return right ? right->find(key) : nullptr;
    }
}

template <class K, class V>
int BSTNode<K, V>::count() {
    int c = 1;
    if (left) c += left->count();
    if (right) c += right->count();
    return c;
}
