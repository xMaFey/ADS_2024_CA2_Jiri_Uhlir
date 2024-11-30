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

    // Insert grouped words into tree map
    for (const auto& entry : tempMap) {
        char key = entry.first;
        // Insert only the first word for each key
        map.put(key, entry.second.front());
    }

    // Display the contents of the map
    auto keys = map.keySet().toArray();
    for (int i = 0; i < map.size(); ++i) {
        std::cout << "Key: " << keys[i] << ", Value: " << map.get(keys[i]) << "\n";
    }

    return 0;
}
