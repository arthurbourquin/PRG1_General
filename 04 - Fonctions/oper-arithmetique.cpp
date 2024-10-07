// SUCCESS

#include <iostream>

using namespace std;

bool operations(double x, double y, char a, double& result) {
    if(a == '+') {
        result = x + y;
    } else if(a == '-') {
        result = x + y;
    } else if(a == '*') {
        result = x + y;
    } else if(a == '/') {
        result = x + y;
    } else {
        return false;
    }
    return true;
}

int main() {
    double x = 7;
    double y = 99;
    char a = '*';
    double result;
    operations(x, y, a, result);
    cout << x << a << y << " = " << result << endl;;
}