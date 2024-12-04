// WIP

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

using Data    = double;
using Ligne   = vector<Data>;
using Matrice = vector<Ligne>;

template <typename T>
T somme(vector<T>& ligne) {
   T somme = T();
   for(T note : ligne) {
      somme += note;
   }
   return somme;
}

template <typename T>
T moyenne(vector<T>& ligne) {
   if(ligne.empty()) {
      return T();
   }
   return somme(ligne) / (T)ligne.size();
}

template <typename T>
void afficher(const vector<T>& ligne) {
   cout << fixed << setprecision(1);
   cout << "[";
   for(T note : ligne) {
      cout << note << " ";
   }
   cout << "]" << "\b\b" << endl;
}

template <typename T, typename Fn>
vector<T> stats(vector<vector<T>> notes, Fn fct) {
   vector<T> resultat;
   resultat.reserve(notes.size());
   for(auto ligne : notes) {
      resultat.push_back(fct(ligne));
   }
   return resultat;
}

int main() {

   const Matrice notes {{4.0, 5.0, 6.0},  // Jean
                        {4.1, 5.1, 4.8},  // Marie
                        {3.5, 4.1     },  // Joshua
                        {4.5, 4.5, 4.6}}; // Ali

   afficher(stats(notes, somme<double>));
   afficher(stats(notes, moyenne<double>));

return EXIT_SUCCESS;
}

/* out:
somme   : [15.0, 14.0, 7.6, 13.6]
moyenne : [5.0, 4.7, 3.8, 4.5]
*/