// WIP

#include <iostream>
#include <iomanip>
using namespace std;

int a = 5;
int b = 13;

void print() {
    cout << setw(a) << 42 << " " << setw(b) << -42 << endl;
}

int main() {

cout << setfill(' ');
cout << endl;

print();
cout << showpos;
print();
cout << noshowpos;
print();

cout << endl;

print();
cout << oct;
print();
cout << showbase;
print();
cout << noshowbase;
print();

cout << endl;

print();
cout << hex;
print();
cout << showbase;
print();
cout << noshowbase;
print();

cout << endl;
    return EXIT_SUCCESS;
}