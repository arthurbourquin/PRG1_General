#include <cmath>
#include <iostream>

using namespace std;

int main() {
    cout << "\"Modulo\" de deux nombres réels." << endl;
    cout << endl;

    while (true) {
        double x, y;

        cout << "Nombre 1 : ";
        cin >> x;
        if (cin.fail()) {
            cout << "Entrée invalide. Fin du programme." << endl;
            break;
        }

        cout << "Nombre 2 : ";
        cin >> y;
        if (cin.fail()) {
            cout << "Entrée invalide. Fin du programme." << endl;
            break;
        }

        if (y == 0) {
            cout << "Erreur : Division par zéro non permise." << endl;
            continue;
        }

        cout << "Résultat: " << fmod(x, y) << endl << endl;
    }

    cout << "Bye." << endl;
    return 0;
}
