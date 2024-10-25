// WIP
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string exit_prg = "tschuss";

int main() {
    cout << "File name (with extension): ";
    string FileName;
    getline(cin, FileName);
    
    ofstream FileOut(FileName, ios::app);
    if(!FileOut) {
        cerr << "Error, guys, the file, bad, not good for " << FileName << endl;
        return 1;
    }

    cout << "Enter the text to put in the file '" << FileName << "'. Line breaks ar allowed. To end, type '" << exit_prg << "'." << endl;
    string line;
    while(getline(cin, line)) {
        if(line == exit_prg) {break;}
        FileOut << line <<"\n";
    }

    FileOut.close();

}