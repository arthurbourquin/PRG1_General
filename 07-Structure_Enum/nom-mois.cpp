#include <iostream>

using namespace std;

bool est_bissextile(int annee){
    return (annee % 400 == 0) || (annee % 100 != 0 && annee % 4 == 0);
}

enum Mois {JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC};

long long duree_mois(int mois, int annee){
    switch(mois) {
        case 2: return est_bissextile(annee) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

int main() {
    int mois;
    cout << "Entrez le mois : " << endl;
    cin >> mois;
    int annee;
    cout << "Entrez l'année : " << endl;
    cin >> annee;
    cout << duree_mois(mois, annee) << " jours" << endl;
}