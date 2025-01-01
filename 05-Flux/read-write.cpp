#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main() {

    // description
    cout << "fstream program, edit read-write.txt, tell us something." << endl;

    // get user inputs
    // get name
    string name;
    cout << "Enter your name: " << endl;
    cin >> name;
    cin.ignore();
    // get story
    string story;
    string line;
    cout << "Tell us something, end with \'END\': " << endl;
    while(true) {
        getline(cin, line);
        if(line == "END") break;
        story += line + '\n';
    }

    // get date and time
    time_t currentTime = time(nullptr);
    char timeBuffer[100];
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

    // write (add) all in existing file
    ofstream outFile("read-write.txt", ios::app);
    outFile << "On " << timeBuffer << " " << name << " said:\n" << story << '\n';
    outFile.close();

    // cout the entire file
    ifstream inFile("read-write.txt");
    if (inFile) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
    }
    inFile.close();


    return 0;
}
