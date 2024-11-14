// WIP

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string to_upper_str(string_view input) {
    string result(input);
    for(char& c : result) {
        c = toupper(c);
    }
    return result;
}

int main() {

    string prenom, nom;
    cout << "Entrez votre prénom puis votre nom (séparés d'un espace) : ";
    cin >> prenom >> nom;

    string acronyme{prenom.at(0), nom.at(0), nom.at(nom.length() - 1)};

    acronyme = to_upper_str(acronyme);

    cout << endl;
    cout << "Prénom     : " << prenom << endl;
    cout << "Nom        : " << nom << endl;
    cout << "Acronyme   : " << acronyme << endl;

return EXIT_SUCCESS;
}