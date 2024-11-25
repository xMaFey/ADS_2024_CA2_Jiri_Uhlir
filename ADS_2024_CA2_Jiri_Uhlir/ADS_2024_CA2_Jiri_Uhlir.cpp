#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cctype>

void processFile(const std::string& filename, BinaryTree<char, std::set<std::string>>& tree) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file." << std::endl;
        return;
    }

    std::string word;
    while (file >> word) {
        // Clean the word: remove punctuation and convert to lowercase
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return std::ispunct(c);
            }), word.end());

        if (word.empty()) continue;

        // Convert to lowercase for uniformity
        for (auto& c : word) {
            c = std::tolower(c);
        }

        char firstLetter = word[0];
        tree.add(firstLetter, std::set<std::string>());
        tree[firstLetter].insert(word);  // Add word to the set associated with the first letter
    }

    file.close();
}

int main() {
    BinaryTree<char, std::set<std::string>> tree;

    // Process the text file
    std::string filename;
    std::cout << "Enter the name of the text file: ";
    std::cin >> filename;

    processFile(filename, tree);

    // Check if tree is empty
    if (tree.size() == 0) {
        std::cout << "No words found in the file." << std::endl;
        return 0;
    }

    // Print the list of letters
    tree.printLetters();

    // Allow the user to see words associated with a given letter
    char letter;
    std::cout << "Enter a letter to view associated words: ";
    std::cin >> letter;

    tree.printWordsForLetter(std::tolower(letter));

    return 0;
}

