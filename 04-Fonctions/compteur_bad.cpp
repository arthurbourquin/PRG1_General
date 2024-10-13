// SUCCESS

#include <iostream>

using namespace std;

int print(int& a) {
    cout << "J'ai été imprimée " << a << " fois." << endl;
    a++;
}

int main() {
    static int x = 0;
    print(x);
    print(x);
    print(x);
    cout << "Salut, ça marche ?" << endl;
    print(x);
    print(x);
    print(x);
    cout << "ééééé" << endl;
    print(x);
    print(x);
    cout << "Cheval" << endl;
    print(x);
    print(x);
}
