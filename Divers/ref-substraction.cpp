#include <iostream>
using namespace std;

int a = 23;
int b = 77;

int main() {

    cout << (&b) - (&a) << endl;

    return 0;
}