// WIP

#include <iostream>
using namespace std;

string vraiFaux(bool b) {
   return b ? "vrai" : "faux";
}

int main() {
   cout << "Entrez un caractère : " << endl;
   char a;
   cin >> a;
   cout << "Code ASCII de '" << a << "'                 : ";
   cout << (int)a << endl;
   cout << "'" << a << "' est une lettre de l'alphabet  : ";
   cout << vraiFaux(isalpha(a)) << endl;

   return EXIT_SUCCESS;  
}