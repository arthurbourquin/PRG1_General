// WIP

#include <iostream>
#include <iomanip>
using namespace std;

const double epsilon = 0.0001;
bool almostEqual(double a, double b){
    return a - b < epsilon;
}

int main() {
    double a = 0.3;
    double b = 0.1 + 0.2;
    cout << "a = " << fixed << setprecision(20) << a << endl;
    cout << "b = " << fixed << setprecision(20) << b << endl;
    cout << "considéré identiques : " << boolalpha << almostEqual(a, b) << endl;
    return EXIT_SUCCESS;
}