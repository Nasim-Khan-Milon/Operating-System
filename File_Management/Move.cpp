#include <iostream>
#include <cstdio>   // for rename()
using namespace std;

int main() {
    string sourceFile, destPath;
    cin >> sourceFile >> destPath;  // Input file name and destination folder path

    string newLocation = destPath + "/" + sourceFile; // Destination full path

    if (rename(sourceFile.c_str(), newLocation.c_str()) == 0) {
        cout << "File moved successfully!" << endl;
    } else {
        cout << "Error: Could not move the file!" << endl;
    }

    return 0;
}
