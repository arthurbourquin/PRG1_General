// WIP

#include <iostream>

using namespace std;

int main() {
    cout << "sizeof()" << endl;
    cout << "s char     : " << sizeof(signed char) << endl;
    cout << "short      : " << sizeof(short) << endl;
    cout << "int        : " << sizeof(int) << endl;
    cout << "long       : " << sizeof(long) << endl;
    cout << "long long  : " << sizeof(long long) << endl;

    cout << endl;

    cout << "sizeof() * CHAR_BIT" << endl;
    cout << "s char     : " << sizeof(signed char) * CHAR_BIT << endl;
    cout << "short      : " << sizeof(short) * CHAR_BIT  << endl;
    cout << "int        : " << sizeof(int) * CHAR_BIT  << endl;
    cout << "long       : " << sizeof(long) * CHAR_BIT  << endl;
    cout << "long long  : " << sizeof(long long) * CHAR_BIT  << endl;    

    return EXIT_SUCCESS;
}