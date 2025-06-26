
//Author: Sagun Pokharel
//Instructor : Professor Alvis Forrest
//Date : June 20, 2025
//Project : Corner Grocer


#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

void DisplayMenu() {
    cout << "\n<-----: Corner Grocer :----->" << endl;
    cout << "1. Search for item frequency" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display histogram of item frequencies" << endl;
    cout << "4. Exit program" << endl;
    cout << "Choose an option (1 to 4): ";
}

int main() {
    GroceryTracker tracker;

    // Load data and write backup
    tracker.LoadDataFromFile("CS210_Project_Three_Input_File.txt");
    tracker.WriteBackupFile("frequency.dat");

    int choice;
    string item;

    do {
        DisplayMenu();
        cin >> choice;

        // Validate input
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1 to 4: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            cout << "Enter the item name: ";
            cin >> item;
            cout << item << " was purchased " << tracker.GetItemFrequency(item) << " times." << endl;
            break;

        case 2:
            cout << "\nAll Item Frequencies:\n";
            tracker.PrintAllFrequencies();
            break;

        case 3:
            cout << "\nItem Frequency Histogram:\n";
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}