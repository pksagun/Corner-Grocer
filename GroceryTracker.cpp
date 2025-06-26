
//Author: Sagun Pokharel
//Instructor : Professor Alvis Forrest
//Date : June 20, 2025
//Project : Corner Grocer


#include "GroceryTracker.h"
using namespace std;

// Load item data from input file
void GroceryTracker::LoadDataFromFile(const string& filename) {
    ifstream inFile(filename);
    string item;

    if (!inFile.is_open()) {
        cout << "Error: Could not open input file." << endl;
        return;
    }

    while (getline(inFile, item)) {
        ++itemFrequency[item];
    }

    inFile.close();
}

// Create frequency backup file
void GroceryTracker::WriteBackupFile(const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Error: Could not create backup file." << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}

// Return frequency of a specific item
int GroceryTracker::GetItemFrequency(const string& item) {
    if (itemFrequency.count(item)) {
        return itemFrequency[item];
    }
    return 0;
}

// Print all items with frequencies
void GroceryTracker::PrintAllFrequencies() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Print histogram using asterisks
void GroceryTracker::PrintHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}