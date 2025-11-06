#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string fileName;
    cin >> fileName;  // Input file name

    ofstream file(fileName);  // Open file for writing (creates or overwrites)

    if (!file) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    string content;
    //cin.ignore();            // Ignore leftover newline from previous input
    getline(cin, content);   // Read a line of text to write

    file << content << endl; // Write the text to file

    cout << "Data written to file successfully!" << endl;

    file.close();            // Close the file
    return 0;
}
