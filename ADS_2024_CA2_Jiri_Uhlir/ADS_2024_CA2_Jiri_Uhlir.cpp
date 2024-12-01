#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include "TreeMap.h"
#include "Employee.h"

using namespace std;

// Function to read employee data from a CSV file
std::map<std::string, std::vector<Employee>> readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::map<std::string, std::vector<Employee>> employeeMap;

    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << ".\n";
        return {};
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, name, department, joiningDate;
        int age;

        // Parse the CSV line
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        ss >> age;
        ss.ignore(1, ',');
        std::getline(ss, department, ',');
        std::getline(ss, joiningDate);

        // Create an Employee object and add it to the map
        Employee emp(id, name, age, department, joiningDate);
        employeeMap[department].push_back(emp); // Grouping employees by department
    }

    file.close();
    return employeeMap;
}

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

    // Load employees from employee_records.csv
    std::map<std::string, std::vector<Employee>> employeeMap = readCSV("employee_records.csv");

    // Allow the user to interact with employee data
    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. View employees by department\n";
        std::cout << "2. Exit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        if (choice == 1) {
            //Display all departments
            std::cout << "Available departments:\n";
            for (const auto& pair : employeeMap) {
                std::cout << "- " << pair.first << "\n";
            }

            std::cout << "Enter department to search: ";
            std::string department;
            std::getline(std::cin, department);

            if (employeeMap.find(department) != employeeMap.end()) {
                std::cout << "Employees in " << department << ":\n";
                for (Employee& emp : employeeMap[department]) {
                    std::cout << "Name: " << emp.getName() << ", ID: " << emp.getId() << ", Age: " << emp.getAge()
                        << ", Joining Date: " << emp.getJoiningDate() << "\n";
                }
            }
            else {
                std::cout << "No employees found in " << department << ".\n";
            }
        }
        else if (choice == 2) {
            break;
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    /*for (string s : map.get(letter[0])) {
        cout << s << endl;
    }*/

    return 0;
}
