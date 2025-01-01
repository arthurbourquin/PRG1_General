#include <iostream>
using namespace std;

int a = 17;
int b = 23;
int* ptr = &a;

void f(int* &x) {
    x++;
}

int main() {

    cout << *ptr << endl;
    f(ptr);
    cout << *ptr << endl;
  
    return 0;
}
