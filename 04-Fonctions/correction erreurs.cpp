#include <cstdlib>
#include <iostream>

using namespace std;

void f(double x);
void g(double &x);
void h(const double &x);
int main() {
    const int C = 1;
    int n = C;
    double x = C;

    f(C);
    f(n);
    f(x);
    g(C);
    g(n);
    g(x);
    h(C);
    h(n);
    h(x);

    return EXIT_SUCCESS;
}
void f(double x) {
    x = x + 1;
    cout << "x = " << x << endl;
}
void g(double &x) {
    x = x + 1;
    cout << "x = " << x << endl;
}
void h(const double &x) {
    x = x + 1;
    cout << "x = " << x << endl;
}