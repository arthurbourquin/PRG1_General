#include <iostream>

using namespace std;

int main() {
    for(int i = 0; i < 20; i++) {
        cout << i % 4 << " " << i / 4 << " " << i << endl;
    }
return EXIT_SUCCESS;
}