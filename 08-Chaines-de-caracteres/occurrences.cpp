// SUCCEESS

#include <iostream>

using namespace std;

int nb_occurences(string_view phrase, string_view motif) {
   int resultat = 0;
   size_t no_char = 0;
   while((no_char = phrase.find(motif, no_char)) != string::npos) {
      resultat++;
      no_char++;
   }
   return resultat;
}

int main() {
    cout << endl;
    cout << "Entrez une phrase puis un suite de caractères et je vous dit combien il y a d'occurences de la suite de caractères dans la phrase.\nEntrez la phrase : " << endl;
    string phrase;
    getline(cin, phrase);
    string motif;
    getline(cin, motif);
    cout << "Il y a " << nb_occurences(phrase, motif) << " fois '" << motif << "' dans la phrase." << endl;
    cout << endl;

return EXIT_SUCCESS;
}