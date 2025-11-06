#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string fileName;
    cin >> fileName;              // Input file name

    ifstream file(fileName);      // Open file for reading

    if (!file) {                  // Check if file exists
        cout << "Error: File not found!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) { // Read file line by line
        cout << line << endl;     // Print each line
    }

    file.close();                 // Close the file

    return 0;
}
