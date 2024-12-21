#include <iostream>
using namespace std;

int main() {

    int a = 1; // former outputs: &a = 0x7ffee4edb778
    int* p = &a;

    cout << &a << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << reinterpret_cast<size_t>(0x7ffee4edb778) << endl;

    return 0;
}
