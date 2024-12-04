#include <iostream>
#include <string_view>
using namespace std;

template <typename x>
x somme(int a, double b) {
    return a + b;
}

int main() {

    cout << somme<double>(1,2) << endl;
    cout << somme<int>(3, 4) << endl;

    return 0;
}