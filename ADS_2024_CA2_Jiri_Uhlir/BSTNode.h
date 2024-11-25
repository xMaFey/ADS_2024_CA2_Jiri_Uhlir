#pragma once
#include <iostream>

template <class K, class V>
class BSTNode {
private:
    K key;
    V value;
    BSTNode<K, V>* parent;
    BSTNode<K, V>* left;
    BSTNode<K, V>* right;

public:
    BSTNode();
    BSTNode(const K& key, const V& value);
    BSTNode(const BSTNode<K, V>& other);
    ~BSTNode();

    BSTNode<K, V>* operator=(const BSTNode<K, V>& other);

    const K& getKey() const;
    const V& getValue() const;
    void setKey(const K& key);
    void setValue(const V& value);

    BSTNode<K, V>* getParent();
    BSTNode<K, V>* getLeft();
    BSTNode<K, V>* getRight();
    void setLeft(BSTNode<K, V>* left);
    void setRight(BSTNode<K, V>* right);

    void add(const K& key, const V& value);
    BSTNode<K, V>* find(const K& key);
    int count();
};
