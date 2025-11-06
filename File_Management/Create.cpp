#include <iostream>
#include <fstream>
using namespace std;

// Function to create a file with the given name
void createFile(string fileName) {
    ofstream file(fileName);     // Create and open the file

    if (file.is_open()) {        // Check if file is created successfully
        cout << "File created successfully!" << endl;
        file.close();            // Close the file
    } else {
        cout << "Failed to create file!" << endl;
    }
}

int main() {
    string fileName;
    cin >> fileName;             // Take filename as input
    createFile(fileName);        // Call the function
}
