#include <iostream>

using namespace std;

enum Mois {JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC};

bool estBissextile(int annee) {
    return (annee % 400 ==0 ) || (annee % 4 == 0 && annee % 100 != 0);
}

long long dureeMois(int mois, int annee) {
    switch (mois) {
        case Mois::FEV: return estBissextile(annee) ? 29 : 28;
        case Mois::JAN: ; case Mois::MAR: ; case Mois::MAI: ; case Mois::JUL: ; case Mois::AOU: ; case Mois::OCT: ; case Mois::DEC: return 31;
        default: return 30;
    }
}

int main() {
    cout << dureeMois((int)Mois::FEV, 2024) << "\n";
    return EXIT_SUCCESS;
}   