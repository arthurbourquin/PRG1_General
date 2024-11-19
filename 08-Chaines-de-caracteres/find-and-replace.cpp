// WIP bof...

#include <iostream>

using namespace std;

string chercher_et_remplacer(string phrase, string_view a_effacer, string_view a_ajouter) {
    for(int i = 0; i < phrase.length(); i++) {
        size_t debut = phrase.find(a_effacer);
        phrase.replace(debut, a_effacer.length(), a_ajouter);
        i += a_ajouter.length();
    }
    return phrase;
}

int main() {
    cout << endl;
    cout << "Chercher et remplacer. " << endl;
    cout << "Phrase : " << endl;
    string phrase;
    getline(cin, phrase);
    cout << "Chercher : " << endl;
    string a_effacer;
    getline(cin, a_effacer);
    cout << "Remplacer par : " << endl;
    string a_ajouter;
    getline(cin, a_ajouter);

    cout << chercher_et_remplacer(phrase, a_effacer, a_ajouter) << endl;

return EXIT_SUCCESS;
}