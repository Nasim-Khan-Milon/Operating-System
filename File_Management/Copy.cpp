#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string sourceFile, destFile;

    cout << "Enter source file name: ";
    cin >> sourceFile;

    cout << "Enter destination file name: ";
    cin >> destFile;

    ofstream src(sourceFile);       // Open source file
    if (!src) {                     // Check if source exists
        cout << "Error: Source file not found!" << endl;
        return 1;
    }

    ofstream dest(destFile);        // Open/create destination file
    dest << src.rdbuf();            // Copy content

    cout << "File copied successfully!" << endl;

    src.close();
    dest.close();

    return 0;
}
