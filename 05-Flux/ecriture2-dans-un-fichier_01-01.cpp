// WIP
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "File name: ";
    string FileName;
    getline(cin, FileName);
    
    ofstream FileOut(FileName, ios::app);
    if(!FileOut) {
        cerr << "Error, guys, the file, bad, not good for " << FileName << endl;
        return 1;
    }

    string line;
    while(getline(cin, line)) {
        if(line == "#exit#") {break;}
        FileOut << line <<"\n";
    }

    FileOut.close();

}