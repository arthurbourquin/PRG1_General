// SUCCESS

#include <iostream>

using namespace std;

int main() {

    double c1;
    cout << "Côté 1 de la base : "<< endl;
    cin >> c1;

    double c2;
    cout << "Côté 2 de la base : "<< endl;
    cin >> c2;

    double h;
    cout << "Hauteur : "<< endl;
    cin >> h;

    double vol = c1 * c2 * h / 3;

    cout << vol << endl;

    return EXIT_SUCCESS;
}