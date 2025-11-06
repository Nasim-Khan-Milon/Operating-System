#include <iostream>
#include <cstdio>  // for remove()
using namespace std;

int main() {
    string fileName;
    cout << "Enter file name to delete: ";
    cin >> fileName;

    if (remove(fileName.c_str()) == 0) {  // remove() needs C-style string
        cout << "File deleted successfully!" << endl;
    } else {
        cout << "Error: Could not delete the file!" << endl;
    }

    return 0;
}
