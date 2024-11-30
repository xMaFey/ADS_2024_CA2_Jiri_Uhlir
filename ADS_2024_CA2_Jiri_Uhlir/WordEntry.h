#pragma once
#include <string>
#include <vector>
#include <iostream>

template <class K, class V>
class WordEntry {
private:
    K key;   // First letter of the word

    std::vector<V> values;
    //V value; // The word itself

public:
    WordEntry(){};

    /*WordEntry(K key, V value) {
        this->key = key;
        this->value = value;
    };*/

    WordEntry(K k, V v) : key(k) {
        values.push_back(v); 
    }

    K getKey() const {
        return this->key;
    };

    const std::vector<V>& getValues() const {
        return values;
    }

    void addValue(const V& v) {
        values.push_back(v);
    }

    V& getValue() {
        return this->values[0];
    };

    // Comparison operator for sorting in the tree (based on the key)
    bool operator<(WordEntry& other) const {
        return key < other.key;
    }

    bool operator>(WordEntry& other) const {
        return key > other.key;
    }

    bool operator==(WordEntry& other) const {
        return key == other.key;
    }

    friend std::ostream& operator<<(std::ostream& out, const WordEntry& entry) {
        out << "Key: " << entry.key << ", Values: ";
        for (const auto& val : entry.values) {
            out << val << " ";  // Print each word separated by a space
        }
        return out;
    }
};