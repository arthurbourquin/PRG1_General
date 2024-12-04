#include <iostream>

using namespace std;

template <typename T> void f(T t) { cout << 1 << endl; }
template <typename T> void f(T* t) { cout << 2 << endl; } // surcharge
template<> void f<int*>(int* t) { cout << 3 << endl; } // spécialisation de 1

int main() {
    f((float)(0));
    f((int)(0));
    f((int*)(0));
    return EXIT_SUCCESS;
}