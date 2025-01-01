#include <iostream>
#include <vector>
#include <array>
#include <span>
#include <cmath>
#include <string>

using namespace std;

enum class Chiffre { ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF };

array<string, 10> CHIFFRE = {"ZERO", "UN", "DEUX", "TROIS", "QUATRE", "CINQ", "SIX", "SEPT", "HUIT", "NEUF"};

ostream& operator<<(ostream& os, Chiffre chiffre) {
   os << CHIFFRE[static_cast<size_t>(chiffre)];
   return os;
}

ostream& operator<<(ostream& os, span<const Chiffre> tab) {
   for (size_t i = 0; i < tab.size(); ++i) {
      if (i) os << " ";
      os << tab[i];
   }
   return os;
}

vector<Chiffre> nbreToEnums(int valeur) {
   if (valeur == 0) return {Chiffre::ZERO};

   vector<Chiffre> result(static_cast<size_t>(log10(valeur)) + 1);
   size_t i = result.size() - 1;

   do {
      result[i--] = Chiffre(valeur % 10);
      valeur /= 10;
   } while (valeur);

   return result;
}

int main() {


   int number = 1234; // Example number
   auto chiffres = nbreToEnums(number);
   cout << span<const Chiffre>(chiffres) << endl;

   return 0;
}
