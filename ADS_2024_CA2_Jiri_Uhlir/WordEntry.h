#pragma once
#include <string>
#include <vector>
#include <iostream>

template <class K, class V>
class WordEntry {
private:
    K key;   // First letter of the word
    V value; // The word itself

public:
    WordEntry(){};

    WordEntry(K key, V value) {
        this->key = key;
        this->value = value;
    };

    K getKey() {
        return this->key;
    };

    /*const std::vector<V>& getValues() const {
        return values;
    }*/

    /*void addValue(const V& v) {
        values.push_back(v);
    }*/

    V& getValue() {
        return this->value;
    };

    // Comparison operator for sorting in the tree (based on the key)
    bool operator<(WordEntry& other) {
        return key < other.key;
    }

    bool operator>(WordEntry& other) {
        return key > other.key;
    }

    bool operator==(WordEntry& other) {
        return key == other.key;
    }

    friend std::ostream& operator<<(std::ostream& out, WordEntry& entity)
    {
        return out << "Key: " << entity.key << ", of value: " << entity.value << "\n";
    }
};