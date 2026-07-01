#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using std::cin, std::cout;
using std::time, std::srand, std::rand;
using std::string;
using std::ifstream, std::ofstream, std::getline;

void printStats(string str) {
    cout << "Max Size: "<< str.max_size() 
    << "\nSize: " << str.size() 
    << "\nLength: " << str.length()
    << "\nEmpty: " << str.empty();
}

bool checkLength(string str, int targ) {
    if (str.length() < targ) {
        return false;
    } else {
        return true;
    }
}

// Modifies string given to add one space after all positions of a certain character targ
void addSpaceAllPos(string &str, char targ, int spacesNeeded) {
    int addedSpace = 0;
    int pos = str.find(targ);

    while (pos != string::npos) {
        if (pos != str.length() - 1 && addedSpace < spacesNeeded) {
            addedSpace++;
            str.insert(pos+1, 1, ' ');
        }
        pos = str.find(targ, pos + 1);
    }
}

// Loops through punctuation, and calls addSpaceAllPos if needed
void modifyPunctuation(string &str, int targ) {
    int numPunc = 6;
    char punc[numPunc] = {'.', ',', '?', '!', ':', ';'};

    for (int i = 0; i < numPunc; i++) {
        if (checkLength(str, targ) == false) {
            addSpaceAllPos(str, punc[i], 1);
        }
    }
}

// Function that formats a whole string
string justifyString(string str, int targ) {
    int randPos, firstSpacePos;

    modifyPunctuation(str, targ);

    while (checkLength(str, targ) == false) {
        randPos = rand()%str.length();
        firstSpacePos = str.find_first_of(' ', randPos);
        if (firstSpacePos == string::npos) {
            firstSpacePos = str.find(' ', 0);
        }

        if (firstSpacePos != string::npos) {
            str.insert(firstSpacePos+1, 1, ' ');
        } else {
            break;
        }
    }

    return str;
}

int main() {
    // Input file 
    string inpf, outpf;
    cout << "Enter input file path including file extension: ";
    cin >> inpf;
    cout << "Enter output file path including file extension: ";
    cin >> outpf;

    ifstream file(inpf);
    string line;

    // Output file
    ofstream outputFile(outpf);

    srand(time(nullptr));
    while (getline(file, line)) {
        if (line.empty()) {
            outputFile << "\n";
        } else {
            if (line.size() > 39) {
                line = justifyString(line, 90);
            }
            outputFile << line << "\n";
        }
    }

    outputFile.close();
}
