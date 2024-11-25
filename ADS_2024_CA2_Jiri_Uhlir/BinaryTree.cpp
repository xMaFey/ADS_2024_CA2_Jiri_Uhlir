#include "BinaryTree.h"

template <class K, class V>
BinaryTree<K, V>::BinaryTree() : root(nullptr) {}

template <class K, class V>
BinaryTree<K, V>::BinaryTree(const BinaryTree<K, V>& other) {
    root = nullptr;
    if (other.root) {
        root = new BSTNode<K, V>(*other.root);
    }
}

template <class K, class V>
BinaryTree<K, V>& BinaryTree<K, V>::operator=(const BinaryTree<K, V>& other) {
    if (this == &other) return *this;
    clear();
    if (other.root) {
        root = new BSTNode<K, V>(*other.root);
    }
    return *this;
}

template <class K, class V>
BinaryTree<K, V>::~BinaryTree() {
    clear();
}

template <class K, class V>
void BinaryTree<K, V>::add(const K& key, const V& value) {
    if (root == nullptr) {
        root = new BSTNode<K, V>(key, value);
    }
    else {
        root->add(key, value);
    }
}

template <class K, class V>
bool BinaryTree<K, V>::remove(const K& key) {
    BSTNode<K, V>* node = root->find(key);
    if (node) {
        // Add removal logic here (not implemented for simplicity)
        return true;
    }
    return false;
}

template <class K, class V>
void BinaryTree<K, V>::clear() {
    if (root) {
        delete root;
        root = nullptr;
    }
}

template <class K, class V>
bool BinaryTree<K, V>::containsKey(const K& key) {
    return root->find(key) != nullptr;
}

template <class K, class V>
V& BinaryTree<K, V>::get(const K& key) {
    BSTNode<K, V>* node = root->find(key);
    if (node) {
        return node->getValue();
    }
    throw std::out_of_range("Key not found");
}

template <class K, class V>
BinaryTree<K, V> BinaryTree<K, V>::keySet() {
    BinaryTree<K, V> keySetTree;
    int pos = 0;
    std::pair<K, V>* arr = new std::pair<K, V>[size()];
    addItemToArray(root, pos, arr);

    for (int i = 0; i < size(); ++i) {
        keySetTree.add(arr[i].first, arr[i].second);
    }
    delete[] arr;
    return keySetTree;
}

template <class K, class V>
int BinaryTree<K, V>::size() {
    return root ? root->count() : 0;
}

template <class K, class V>
bool BinaryTree<K, V>::removeKey(const K& key) {
    return remove(key);
}

template <class K, class V>
V& BinaryTree<K, V>::operator[](const K& key) {
    return get(key);
}

template <class K, class V>
void BinaryTree<K, V>::printInOrder() {
    printInOrderHelper(root);
}

template <class K, class V>
void BinaryTree<K, V>::printInOrderHelper(BSTNode<K, V>* node) {
    if (node) {
        printInOrderHelper(node->getLeft());
        std::cout << node->getKey() << ": " << node->getValue() << std::endl;
        printInOrderHelper(node->getRight());
    }
}

template <class K, class V>
void BinaryTree<K, V>::printLetters() {
    if (!root) {
        std::cout << "No letters in the tree." << std::endl;
        return;
    }
    std::cout << "Letters with words in the file:" << std::endl;
    printLettersHelper(root);
    std::cout << std::endl;
}

template <class K, class V>
void BinaryTree<K, V>::printLettersHelper(BSTNode<K, V>* node) {
    if (node) {
        printLettersHelper(node->getLeft());
        std::cout << node->getKey() << std::endl; // Print the letter (key)
        printLettersHelper(node->getRight());
    }
}

template <class K, class V>
void BinaryTree<K, V>::printWordsForLetter(const K& letter) {
    BSTNode<K, V>* node = root->find(letter);
    if (node) {
        std::cout << "Words associated with '" << letter << "': " << node->getValue() << std::endl;
    }
    else {
        std::cout << "No words found for letter '" << letter << "'" << std::endl;
    }
}

template <class K, class V>
void BinaryTree<K, V>::addItemToArray(BSTNode<K, V>* node, int& pos, std::pair<K, V>* arr) {
    if (node != nullptr) {
        addItemToArray(node->getLeft(), pos, arr);
        arr[pos] = { node->getKey(), node->getValue() };
        pos++;
        addItemToArray(node->getRight(), pos, arr);
    }
}

template <class K, class V>
void BinaryTree<K, V>::printWordsForLetter(const K& letter) {
    if (!std::isalpha(letter)) {
        std::cout << "Invalid letter input: " << letter << std::endl;
        return;
    }
    BSTNode<K, V>* node = root ? root->find(letter) : nullptr;
    if (node) {
        std::cout << "Words associated with '" << letter << "': ";
        for (const auto& word : node->getValue()) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No words found for letter '" << letter << "'" << std::endl;
    }
}
