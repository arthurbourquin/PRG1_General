#include <iostream>
using namespace std;

int a = 1; int b = 2;

void switch_ref(int& x, int& y) {int temp = x; x = y; y = temp;}
void switch_val(int x, int y) {int temp = x; x = y; y = temp;}

int main() {
    cout << "a: " << a << "   b: " << b << endl;
    char f = 'x';
    while(true){
        while(true) {
            cout << "switch by value or switch by reference? v/r: ";
            cin >> f;
            if(f != 'v' || f != 'x') {break;}
        }
        if(f == 'v'){
            switch_val(a, b);
        } else {
            switch_ref(a, b);
        }
        cout << "a: " << a << "   b: " << b << endl;
        f = 'x';
    }
    return 0;
}