#include <iostream>
#include <fstream>
#include <cstdio>   // for remove() and rename()
using namespace std;

void createFile(string fileName) {
    ofstream file(fileName);
    if (file) {
        cout << "File created successfully!\n";
        file.close();
    } else {
        cout << "Failed to create file!\n";
    }
}

void deleteFile(string fileName) {
    ofstream file(fileName);
    if (remove(fileName.c_str()) == 0)
        cout << "File deleted successfully!\n";
    else
        cout << "Error: Could not delete the file!\n";
}

void copyFile(string sourceFile, string destFile) {
    ofstream src(sourceFile);
    if (!src) {
        cout << "Error: Source file not found!\n";
        return;
    }
    ofstream dest(destFile);
    dest << src.rdbuf();
    cout << "File copied successfully!\n";
    src.close();
    dest.close();
}

void moveFile(string src, string dst){
    copyFile(src, dst);  // Copy to new location
    deleteFile(src);     // Delete original
}

void writeFile(string fileName, string content) {
    ofstream file(fileName);
    if (!file) {
        cout << "Error: Could not open file!\n";
        return;
    }
    file << content << endl;
    cout << "Data written to file successfully!\n";
    file.close();
}

void readFile(string fileName) {
    ifstream file(fileName);
    if (!file) {
        cout << "Error: File not found!\n";
        return;
    }
    string line;
    while (getline(file, line))
        cout << line << endl;
    file.close();
}

int main() {
    int choice;
    cout << "File Management Operations:\n";
    cout << "1. Create\n2. Delete\n3. Copy\n4. Move\n5. Write\n6. Read\n";
    cin >> choice;

    string fileName, destFile, destPath, content;

    switch (choice) {
        case 1:
            cin >> fileName;
            createFile(fileName);
            break;
        case 2:
            cin >> fileName;
            deleteFile(fileName);
            break;
        case 3:
            cin >> fileName >> destFile;
            copyFile(fileName, destFile);
            break;
        case 4:
            cin >> fileName >> destPath;
            moveFile(fileName, destPath);
            break;
        case 5:
            cin >> fileName;
            cin.ignore();
            getline(cin, content);
            writeFile(fileName, content);
            break;
        case 6:
            cin >> fileName;
            readFile(fileName);
            break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}
