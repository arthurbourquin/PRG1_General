// success

#include <iostream>

using namespace std;

// opérateur ternaire

int& min(int& a, int& b, int&c){
    return a < c ? (a < b ? a : b) : (b < a ? a : b);
}

int main() {

    int a = 5;
    int b = 2;
    int c = 9;

    cout << min(a, b, c) << endl;
    min(a, b, c) = 1;
    int& d = min(a, b, c);

}