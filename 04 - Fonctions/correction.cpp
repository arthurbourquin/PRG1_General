// SUCCESS

#include <cstdlib>
#include <iostream>

using namespace std;

void f() {
   cout << "Appel de f" << endl;
}

void g(int i, double j) {
   cout << "Appel de g avec i = " << i << " et j = " << j << endl;
}

void h(int i, char c) {
   cout << "Appel de h avec i = " << i << " et c = " << c << endl;
}
int main() {
   f();
   g(1, 2.0);
   h(64, 65);

   return EXIT_SUCCESS;
}