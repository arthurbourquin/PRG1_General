#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool lire_notes(vector<double>& notes) { // Pass by reference
   string notes_str;
   getline(cin, notes_str);
   stringstream notes_ss(notes_str);
   string token;

   for (size_t i = 0; i < notes.size(); ++i) {
      if (!getline(notes_ss, token, ' ')) return false; // Read up to ';'
      try {
         notes[i] = stod(token); // Convert to double
      } catch (...) {
         return false; // Handle invalid number
      }
   }
   return true;
}

int main() {
   vector<double> notes;
   cout << "Entrez les notes séparées par un espace : ";
   cout <<
      (lire_notes(notes) ?
         "Les notes ont été lues." :
         "Les notes n'ont pas pu être lues.")
      << endl;

   cout << "Notes lues : ";
   for (double note : notes) {
      cout << note << " ";
   }
   cout << endl;

   double somme = 0;
   for (double note : notes) {
      somme += note;
   }
   cout << "Moyenne : " << (somme / notes.size()) << endl;

   return EXIT_SUCCESS;
}
