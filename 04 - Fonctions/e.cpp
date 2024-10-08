// WIP FAIL

#include <iostream>

using namespace std;

double e = 1;
double i = 0;
double d = 1;

int main() {
    while(true) {
        for(int j = 0; j < i; j++){
            d += i;
            j++;
        }
        e += 1 / d;
        cout << e << endl;
        i++;
    }
}