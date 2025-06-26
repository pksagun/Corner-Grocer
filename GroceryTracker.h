
//Author: Sagun Pokharel
//Instructor : Professor Alvis Forrest
//Date : June 20, 2025
//Project : Corner Grocer


#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency; // Stores item name and frequency

public:
    // Loads data and fills the map
    void LoadDataFromFile(const std::string& filename);

    // Writes item frequencies to a backup file
    void WriteBackupFile(const std::string& filename);

    // Returns the frequency of a given item
    int GetItemFrequency(const std::string& item);

    // Prints all item frequencies
    void PrintAllFrequencies();

    // Prints a histogram 
    void PrintHistogram();
};

#endif#pragma once
