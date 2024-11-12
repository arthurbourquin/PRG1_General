// caca presque

#include <iostream>

using namespace std;

int valeur_du_chiffre_romain(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
}

int valeur_du_nombre_romain(string nombre_romain) {
    int result = 0;
    for(int i = 0; i < nombre_romain.length() - 1; i++) {
        int valeur_courante = valeur_du_chiffre_romain(nombre_romain[i]);
        int valeur_suivante = valeur_du_chiffre_romain(nombre_romain[i + 1]);
        if(valeur_courante >= valeur_suivante) {
            result += valeur_courante;
        } else {
            result -= valeur_courante;
        }
        cout << result << endl;
    }

    int valeur_du_dernier_chiffre_romain = valeur_du_chiffre_romain(nombre_romain[nombre_romain.length() - 1]);
    result += valeur_du_dernier_chiffre_romain;

    return result;
}

int main() {
    cout << "Entrer un nombre romain : " << endl;
    string s;
    cin >> s;
    cout << valeur_du_nombre_romain(s) << endl;

    return EXIT_SUCCESS;
}