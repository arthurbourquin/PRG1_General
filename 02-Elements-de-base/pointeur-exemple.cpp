#include <iostream>

using namespace std;

int main() {

    cout << endl;

    cout << "int a = 7; int* p;" << endl;
    int a = 7; int* p;
    cout << "a: " << a << "    &a: " << &a << "    p: " << p << "    *p: " << *p << endl;

    cout << "p = &a;" << endl;
    p = &a;
    cout << "a: " << a << "    &a: " << &a << "    p: " << p << "    *p: " << *p << endl;
    
    cout << "*p = 4;" << endl;
    *p = 4;
    cout << "a: " << a << "    &a: " << &a << "    p: " << p << "    *p: " << *p << endl;
    
    cout << "a = 9;" << endl;
    a = 9;
    cout << "a: " << a << "    &a: " << &a << "    p: " << p << "    *p: " << *p << endl;

    cout << endl;

    return EXIT_SUCCESS;
}
