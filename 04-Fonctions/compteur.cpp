// SUCCESS

#include <iostream>

using namespace std;

int print() {
    static int x = 0;
    cout << "J'ai été imprimée " << x << " fois." << endl;
    x++;
}

int main() {
    print();
    print();
    print();
    cout << "Salut, ça marche ?" << endl;
    print();
    print();
    print();
    print();
    cout << "ééééé" << endl;
    print();
    print();
    cout << "Cheval" << endl;
    print();
    print();
}
