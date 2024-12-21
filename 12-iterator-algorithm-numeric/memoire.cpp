#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int leint[] = {}; 
double ledouble[] = {};
size_t lesizet[] = {};

int main() {

    int i = 0;
    while(true) {
        cout << dec << &leint << " " << &leint[i] << " " << leint[i] << endl;
        cout << dec << &ledouble << " " << &ledouble[i] << " " << ledouble[i] << endl;
        cout << dec << &lesizet << " " << &lesizet[i] << " " << lesizet[i] << endl;
        ++i;
    }
    return 0;
}