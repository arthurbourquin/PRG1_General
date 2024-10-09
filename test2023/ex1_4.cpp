#include <iostream>

using namespace std;

int main() {
    for(int i = 4; i > 0; --i){
        switch(i){
            case 0: cout << "A";
            case 1: cout << "B";
            case 2: cout << "C"; break;
            default: cout << "D";
        }
        cout << "-";
    }
    cout << endl;
}

// D-D-C-BC-