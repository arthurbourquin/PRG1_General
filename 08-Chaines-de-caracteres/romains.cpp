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
    }

    int valeur_du_dernier_chiffre_romain = valeur_du_chiffre_romain(nombre_romain[nombre_romain.length() - 1]);
    result += valeur_du_dernier_chiffre_romain;

    return result;
}

void test_de_la_fonction() {
    cout << "XIV = 14 : " << valeur_du_nombre_romain("XIV") << endl;
    cout << "LXXV = 75 : " << valeur_du_nombre_romain("LXXV") << endl;
    cout << "CXXIII = 123 : " << valeur_du_nombre_romain("CXXIII") << endl;
    cout << "CDXL = 440 : " << valeur_du_nombre_romain("CDXL") << endl;
    cout << "MMMCMXCIX = 3999 : " << valeur_du_nombre_romain("MMMCMXCIX") << endl;
    cout << "DCCCXC = 890 : " << valeur_du_nombre_romain("DCCCXC") << endl;
    cout << "MMXXIV = 2024 : " << valeur_du_nombre_romain("MMXXIV") << endl;
    cout << "DCCLXXVII = 777 : " << valeur_du_nombre_romain("DCCLXXVII") << endl;
    cout << "MMMMMMMMMMMMCCCXLV = 12345 : " << valeur_du_nombre_romain("MMMMMMMMMMMMCCCXLV") << endl;
}

int main() {

    cout << endl;
    test_de_la_fonction();
    cout << "Entrer un nombre romain : " << endl;
    string s;
    cin >> s;
    cout << valeur_du_nombre_romain(s) << endl;

    return EXIT_SUCCESS;
}