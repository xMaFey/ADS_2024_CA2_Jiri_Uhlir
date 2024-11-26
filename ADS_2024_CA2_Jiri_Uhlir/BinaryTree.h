#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BSTNode.h"
#include <vector>
#include <stdexcept>

template <class T>
class BinaryTree {
private:
    BSTNode<T>* root;

    void addItemToArray(BSTNode<T>* node, int& pos, T* arr) {
        if (node != nullptr) {
            addItemToArray(node->getLeft(), pos, arr);
            arr[pos++] = node->getItem();
            addItemToArray(node->getRight(), pos, arr);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    BinaryTree(const BinaryTree<T>& other) {
        root = nullptr;
        if (other.root != nullptr)
            root = new BSTNode<T>(*other.root);
    }

    BinaryTree<T>& operator=(const BinaryTree<T>& other) {
        if (this == &other)
            return *this;
        if (other.root != nullptr)
            root = new BSTNode<T>(*other.root);
        else
            root = nullptr;
        return *this;
    }

    void add(T& item) {
        if (root == nullptr) {
            root = new BSTNode<T>(item);
        }
        else {
            root->add(item);
        }
    }

    int count() {
        return (root == nullptr) ? 0 : root->count();
    }

    bool remove(T& item) {
        BSTNode<T>* toBeRemoved = root;
        BSTNode<T>* parent = nullptr;
        bool found = false;

        while (!found && toBeRemoved != nullptr) {
            if (toBeRemoved->getItem() == item) {
                found = true;
            }
            else {
                parent = toBeRemoved;
                if (toBeRemoved->getItem() > item) {
                    toBeRemoved = toBeRemoved->getLeft();
                }
                else {
                    toBeRemoved = toBeRemoved->getRight();
                }
            }
        }
        if (!found) return false;

        if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr) {
            BSTNode<T>* newChild = (toBeRemoved->getLeft() == nullptr) ? toBeRemoved->getRight() : toBeRemoved->getLeft();
            if (parent == nullptr) {
                root = newChild;
            }
            else if (parent->getLeft() == toBeRemoved) {
                parent->setLeft(newChild);
            }
            else {
                parent->setRight(newChild);
            }
            delete toBeRemoved;
            return true;
        }

        BSTNode<T>* smallestParent = toBeRemoved;
        BSTNode<T>* smallest = toBeRemoved->getRight();
        while (smallest->getLeft() != nullptr) {
            smallestParent = smallest;
            smallest = smallest->getLeft();
        }
        toBeRemoved->setItem(smallest->getItem());
        if (smallestParent == toBeRemoved) {
            smallestParent->setRight(smallest->getRight());
        }
        else {
            smallestParent->setLeft(smallest->getRight());
        }
        delete smallest;
        return true;
    }

    T& get(T& item) {
        BSTNode<T>* current = root;
        while (current != nullptr) {
            if (current->getItem() == item)
                return current->getItem();
            else if (current->getItem() > item)
                current = current->getLeft();
            else
                current = current->getRight();
        }
        throw std::logic_error("Item not found");
    }

    void clear() {
        delete root;
        root = nullptr;
    }

    std::vector<T> toArray() {
        std::vector<T> arr;
        int pos = 0;
        arr.resize(root ? root->count() : 0);
        addItemToArray(root, pos, arr.data());
        return arr;
    }

    // Additional methods like keySet(), containsKey(), size(), etc., can be added here.
};

#endif // BINARYTREE_H
