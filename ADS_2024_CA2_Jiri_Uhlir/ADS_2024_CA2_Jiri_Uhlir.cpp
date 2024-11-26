#include "BinaryTree.h"
#include <iostream>

int main() {
    BinaryTree<int> tree;

    // Add items
    int val1 = 10, val2 = 20, val3 = 5;
    tree.add(val1);
    tree.add(val2);
    tree.add(val3);

    // Test get()
    try {
        std::cout << "Item found: " << tree.get(val1) << std::endl;
    }
    catch (std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }

    // Remove an item
    tree.remove(val2);

    // Test size
    std::cout << "Tree size: " << tree.count() << std::endl;

    // Convert tree to array
    std::vector<int> arr = tree.toArray();
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Clear the tree
    tree.clear();

    return 0;
}
