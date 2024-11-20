#include "BinaryTree.h"   // Include the BinaryTree header file to use the BinaryTree template class

// Template definition for BinaryTree methods

template <class T>
BinaryTree<T>::BinaryTree() {  // Constructor definition
    root = nullptr;  // Initialize root to nullptr
}

template <class T>
BinaryTree<T>::~BinaryTree() {  // Destructor definition
    if (root != nullptr) {
        delete root;  // Delete the root node to free memory
        root = nullptr;  // Set root to nullptr after deletion
    }
}

template <class T>
void BinaryTree<T>::add(T& item) {  // Add item to the BinaryTree
    if (root == nullptr) {
        root = new BSTNode<T>(item);  // Create new node if root is nullptr
    }
    else {
        root->add(item);  // Add item recursively if root exists
    }
}

template <class T>
int BinaryTree<T>::count() {  // Return the count of nodes in the tree
    if (root == nullptr) {
        return 0;  // Return 0 if root is nullptr
    }
    return root->count();  // Call count on root node
}

template <class T>
bool BinaryTree<T>::remove(T& item) {  // Remove item from the tree
    BSTNode<T>* toBeRemoved = root;
    BSTNode<T>* parent = nullptr;
    bool found = false;

    while (!found && toBeRemoved != nullptr) {
        if (toBeRemoved->getItem() == item) {
            found = true;  // Item found in the tree
        }
        else {
            parent = toBeRemoved;
            if (toBeRemoved->getItem() > item) {
                toBeRemoved = toBeRemoved->getLeft();  // Move to the left child
            }
            else {
                toBeRemoved = toBeRemoved->getRight();  // Move to the right child
            }
        }
    }

    if (!found) {
        return false;  // Item not found
    }

    // Handling deletion logic for nodes with one or no child
    if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr) {
        BSTNode<T>* newChild;
        if (toBeRemoved->getLeft() == nullptr) {
            newChild = toBeRemoved->getRight();
        }
        else {
            newChild = toBeRemoved->getLeft();
        }
        if (parent == nullptr) {
            root = newChild;
        }
        else if (parent->getLeft() == toBeRemoved) {
            parent->setLeft(newChild);
        }
        else {
            parent->setRight(newChild);
        }
        return true;
    }

    // Deleting node with two children
    BSTNode<T>* smallestParent = toBeRemoved;
    BSTNode<T>* smallest = toBeRemoved->getRight();
    while (smallest->getLeft() != nullptr) {
        smallestParent = smallest;
        smallest = smallest->getLeft();  // Find the smallest node in the right subtree
    }

    toBeRemoved->setItem(smallest->getItem());  // Replace node with the smallest node
    if (smallestParent == toBeRemoved) {
        smallestParent->setRight(smallest->getRight());
    }
    else {
        smallestParent->setLeft(smallest->getRight());
    }

    return true;  // Return true after removal
}

template <class T>
T& BinaryTree<T>::get(T& item) {  // Get item from the tree
    bool found = false;
    BSTNode<T>* current = root;

    while (!found) {
        if (current == nullptr) {
            break;
        }

        if (current->getItem() == item) {
            return current->getItem();  // Item found
        }
        else if (current->getItem() > item) {
            current = current->getLeft();  // Move to left child
        }
        else {
            current = current->getRight();  // Move to right child
        }
    }

    throw logic_error("Item not found");  // Throw exception if item not found
}

template <class T>
void BinaryTree<T>::addItemToArray(BSTNode<T>* node, int& pos, T* arr) {  // Helper function to convert tree to array
    if (node != nullptr) {
        addItemToArray(node->getLeft(), pos, arr);  // Traverse left subtree
        arr[pos] = node->getItem();  // Add item to array
        pos++;  // Increment position
        addItemToArray(node->getRight(), pos, arr);  // Traverse right subtree
    }
}

template <class T>
T* BinaryTree<T>::toArray() {  // Convert BinaryTree to array
    T* arr = new T[root->count()];  // Allocate array with size equal to node count
    int pos = 0;
    addItemToArray(root, pos, arr);  // Call helper function to fill the array
    return arr;  // Return the array
}

template <class T>
void BinaryTree<T>::clear() {  // Clear the BinaryTree
    delete root;  // Delete root and all its children
    root = nullptr;  // Set root to nullptr
}

template <class T>
void BinaryTree<T>::printInOrder() {  // Print nodes in order
    this->printInOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printInOrder(BSTNode<T>* node) {  // In-order traversal
    if (node != nullptr) {
        printInOrder(node->getLeft());  // Traverse left subtree
        cout << node->getItem() << " ";  // Print current node's item
        printInOrder(node->getRight());  // Traverse right subtree
    }
}

template <class T>
void BinaryTree<T>::printPreOrder() {  // Print nodes in pre-order
    this->printPreOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printPreOrder(BSTNode<T>* node) {  // Pre-order traversal
    if (node != nullptr) {
        cout << node->getItem() << " ";  // Print current node's item
        printPreOrder(node->getLeft());  // Traverse left subtree
        printPreOrder(node->getRight());  // Traverse right subtree
    }
}

template <class T>
void BinaryTree<T>::printPostOrder() {  // Print nodes in post-order
    this->printPostOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printPostOrder(BSTNode<T>* node) {  // Post-order traversal
    if (node != nullptr) {
        printPostOrder(node->getLeft());  // Traverse left subtree
        printPostOrder(node->getRight());  // Traverse right subtree
        cout << node->getItem() << " ";  // Print current node's item
    }
}

}