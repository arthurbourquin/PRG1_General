#include <iostream>
#include <vector>
#include <span>
#include <string>
#include <algorithm> // Pour std::fill
using namespace std;

void f(float a, int &b) {cout << "f1" << endl;}
void f(double a, const int &b) {cout << "f2" << endl;}
void f(float &a, unsigned short b) {cout << "f3" << endl;}
int main() {
    int i = 5;
    float x = 3.f;
    double d = 1.2; unsigned short k = 2;
    f(5.5, 5);
    f(5ull, i);
    f(3.f, k);
    f(1.f, 5);
//  f(d, i);
    f(x, x);
    f(x, k);
//  f(x, 1);
    return 0;
}