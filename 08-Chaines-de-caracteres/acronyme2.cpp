// WIP

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

string to_upper_str(string_view input) {
    string result(input);
    for(char& c : result) {
        c = toupper(c);
    }
    return result;
}

int main() {

    string personne;
    cout << "Entrez votre prénom puis votre nom : ";
    getline(cin, personne);

    char c_1 = personne[0];
    int debut_nom = max(personne.find_last_of(' '), personne.find_last_of('\''));
    char c_2 = personne[debut_nom + 1];
    char c_3 = personne[personne.length() -1];

    string acronyme{c_1, c_2, c_3};

    acronyme = to_upper_str(acronyme);

    cout << endl;
    cout << debut_nom << endl;
    cout << "Acronyme   : " << acronyme << endl;

return EXIT_SUCCESS;
}