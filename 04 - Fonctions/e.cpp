// WIP FAIL

#include <iostream>

using namespace std;

int main() {

    int i = 0;
    double a = 0;
    double d = 1;

    while(true) {
        for(int j = 0; j < i; j++) {
            d++;
        }
        a = a + (1 / d);
        cout << a << endl; // << "i" << i << "d" << d << "a"
        i++;
    }
}