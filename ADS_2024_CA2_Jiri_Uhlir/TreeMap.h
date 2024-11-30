#pragma once
#include "BinaryTree.h"
#include "WordEntry.h"

template <class K, class V>
class TreeMap
{
    BinaryTree<WordEntry<K, V>> tree;

    void keyPreOrder(BSTNode<WordEntry<K, V>>* node, BinaryTree<K>& out);

public:
    TreeMap();

    void put(K& key, const V& value);
    V& get(K key);
    V& operator[](K key);
    void clear();

    bool containsKey(K key);
    BinaryTree<K> keySet();
    bool removeKey(K key);
    int size();
};

template<class K, class V>
TreeMap<K, V>::TreeMap() { }

template<class K, class V>
void TreeMap<K, V>::put(K& key, const V& value)
{
    WordEntry<K, V> entry(key, value);
    WordEntry<K, V> existingEntry(key);  // Create a temporary entry for checking

    if (tree.contains(existingEntry)) {
        existingEntry = tree.get(existingEntry);
        existingEntry.addValue(value);  // Add the word to the existing entry's values
    }
    else {
        tree.add(entry);  // Add the entry if it's a new key
    }
}

template<class K, class V>
V& TreeMap<K, V>::get(K key)
{
    WordEntry<K, V> entry(key, V());
    WordEntry<K, V>& result = tree.get(entry);
    return result.getValue();
}

template<class K, class V>
V& TreeMap<K, V>::operator[](K key)
{
    return this->get(key);
}

template<class K, class V>
void TreeMap<K, V>::clear()
{
    tree.clear();
}

template<class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
    WordEntry<K, V> entry(key);
    return tree.contains(entry);
}

template<class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
    BinaryTree<K> keyTree;
    keyPreOrder(tree.root, keyTree);
    return keyTree;
}

template<class K, class V>
void TreeMap<K, V>::keyPreOrder(BSTNode<WordEntry<K, V>>* node, BinaryTree<K>& out)
{
    if (node == nullptr) {
        return;
    }

    WordEntry<K, V> entry = node->getItem();
    K ent = entry.getKey();
    out.add(ent);

    keyPreOrder(node->getLeft(), out);
    keyPreOrder(node->getRight(), out);
}

template<class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
    WordEntry<K, V> entry(key);
    return tree.remove(entry);
}

template<class K, class V>
int TreeMap<K, V>::size()
{
    return tree.count();
}