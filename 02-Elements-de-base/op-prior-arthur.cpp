#include <iostream>
using namespace std;
int main() {
    int a = 0; int b = 0; int c = 0;
    cout << a++ << ++b << endl;
    cout << (a *= b *= 2) << endl;
    cout << (++a || b == 4) << endl;
    cout << (c = 10, a > b ? (a = 0) : (b > c)) << c << endl;
    int d = c++ > a || a++ < b;
    cout << d << endl;
    return EXIT_SUCCESS;
}
