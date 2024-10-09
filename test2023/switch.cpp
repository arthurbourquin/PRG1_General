#include <iostream>

using namespace std;

int main() {
    cout << "case number: ";
    int a = 0;
    cin >> a;
    switch(a){
        case 0: cout << "case 0" << endl;
        case 1: cout << "case 1" << endl;
        case 2: cout << "case 2" << endl;
        case 10: cout << "case 10" << endl;
        default: cout << "default" << endl;
    }
}