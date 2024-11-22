#include <iostream>
#include <sstream>
using namespace std;

int main() {
    stringstream ss;
    
    streambuf* cin_buffer = cin.rdbuf();  
    cin.rdbuf(ss.rdbuf());  

    string input;
    getline(cin, input);  
    cout << "Entrée capturée dans stringstream: " << input << endl;

    cin.rdbuf(cin_buffer);

    return 0;
}