#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "TreeMap.h"

int main() {
    TreeMap<char, std::vector<string>> map;

    std::ifstream file("Text.txt");

    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::string word;

    //Read the file and add words to TreeMap
    while (getline(file, word)) {
        if (map.containsKey(word[0])) {
            bool newWord = true;
            for (std::string& w : map.get(word[0])) {
                if (w == word) {
                    newWord = false;
                    break; //do not store duplicates
                }
            }
            if (newWord) {
                map.get(word[0]).push_back(word);
            }
        }
        else {
            vector<string> value = {word};
            map.put(word[0], value);
        }
    }

    file.close();
    
    BinaryTree<char> set = map.keySet();
    set.printInOrder();

    // Display words for selected letter
    string letter;          //cannot use char for getline
    cout << "\nEnter a letter to search for words: ";
    getline(cin, letter);

    // Make sure the input has at least one character
    if (!letter.empty()) {
        char key = letter[0];
        if (map.containsKey(key)) {
            for (const std::string& s : map.get(key)) {
                std::cout << s << std::endl;
            }
        }
        else {
            std::cout << "No words found for the letter '" << key << "'.\n";
        }
    }
    else {
        std::cout << "Invalid input.\n";
    }

    /*for (string s : map.get(letter[0])) {
        cout << s << endl;
    }*/

    return 0;
}
