#include <iostream>
#include <string>
using namespace std;

int main() {
    string userString;
    int userNumber;
    string line;

    // Ask for a string input
    cout << "Enter a string: ";
    getline(cin, userString);

    // Ask for a number input
    cout << "Enter a number: ";
    while (!(cin >> userNumber)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }

    // Ignore the newline character left in the buffer after reading the number
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Ask for several lines of input
    cout << "Enter multiple lines (type 'end' to stop):\n";
    string lines;
    while (true) {
        getline(cin, line);
        if (line == "end") break;
        lines += line + "\n";
    }

    // Output the collected inputs
    cout << "\nYou entered:\n";
    cout << "String: " << userString << endl;
    cout << "Number: " << userNumber << endl;
    cout << "Lines: " << endl << lines;

    return 0;
}
