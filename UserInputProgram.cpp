#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to reverse the content of the file
void reverseFileContent(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error opening input file: " << inputFile << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    reverse(content.begin(), content.end());

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error opening output file: " << outputFile << endl;
        return;
    }
    outFile << content;
    outFile.close();
}

int main() {
    string filename = "CSC450_CT5_mod5.txt";
    string reversedFilename = "CSC450-mod5-reverse.txt";

    // Read and display file contents before appending
    ifstream inFile(filename);
    if (inFile) {
        cout << "Current file contents before appending:" << endl;
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cerr << "File does not exist or cannot be opened. It will be created." << endl;
    }

    // Get user input
    cout << "Enter text to append to the file: ";
    string userInput;
    getline(cin, userInput);

    // Append input to file
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Error opening file for appending: " << filename << endl;
        return 1;
    }
    outFile << userInput << endl;
    outFile.close();

    // Read and display file contents after appending
    inFile.open(filename);
    if (inFile) {
        cout << "File contents after appending:" << endl;
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    // Reverse file contents and store in new file
    reverseFileContent(filename, reversedFilename);

    cout << "Operation completed. The reversed content is saved in " << reversedFilename << endl;
    return 0;
}
