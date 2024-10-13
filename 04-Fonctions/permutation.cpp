// SUCCESS

#include <iostream>

using namespace std;

void permutation(double& a, double& b, double& c) {
    double t = c;
    c = b;
    b = a;
    a = t;
}

int main() {
    double a = 7;
    double b = 12;
    double c = 1234;
    cout << a << " " << b << " " << c << endl;
    permutation(a, b, c);
    cout << a << " " << b << " " << c << endl;

}
