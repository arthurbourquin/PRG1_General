#include <iostream>
#include <sstream>
using namespace std;

int main() {

    int val = 357;
    int* ptr = &val;
    int& ref = val;

    cout << endl;
    cout << val << endl;
    cout << &val << endl;
    cout << endl;
    cout << &ptr << endl;
    cout << *ptr << endl;
    cout << ptr << endl;
    cout << endl;
    cout << ref << endl;
    cout << &ref << endl;
    cout << endl;

    return 0;
}