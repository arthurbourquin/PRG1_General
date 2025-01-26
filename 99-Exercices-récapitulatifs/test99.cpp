#include <iostream>
#include <vector>
using namespace std;

int main() {

    for(int i = 0; i < 256; ++i) {
        cout << (char)(i) << " ";
        if(i % 16 == 0) cout << endl;
    }


    cout << endl;
    cout << endl;
    cout << (int)('A') - (int)('a') << endl;
    cout << endl;

    return 0;
}