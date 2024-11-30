#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "TreeMap.h"

int main() {
    TreeMap<char, std::string> map;

    std::ifstream file("Text.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::string word;
    //Temporary map to store words with the first letter
    std::map<char, std::vector<std::string>> tempMap;

    //read words from file and group them by first letter
    while (file >> word) {
        char firstLetter = word[0];
        tempMap[firstLetter].push_back(word);
    }

    file.close();

    //Insert grouped words into tree map
    for (const auto& entry : tempMap) {
        char key = entry.first;
        //Iterate through vector of words for this key
        for (const std::string& w : entry.second) {
            map.put(key, w);
        }
    }

    // Displaying the contents of the map
    auto keys = map.keySet().toArray();
    for (int i = 0; i < map.size(); ++i) {
        std::cout << "Key: " << keys[i] << ", Values: ";
        
        const auto& values = map.get(keys[i]);
        //Display words separated by commas
        for (size_t j = 0; j < values.size(); ++j) {
            std::cout << values[j];
            if (j < values.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
