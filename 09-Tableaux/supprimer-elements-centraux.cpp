// WIP

#include <iostream>
#include <vector>
using namespace std;

void imprimer_le_vecteur(vector<string> v) {
   for(int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
   }
   cout << endl;
}

void supprimer_elements_centraux(vector<string> &v) {
   if(v.empty()) {return;}
   if(v.size() % 2 != 0) {
      int i = v.size() / 2;
      while(i < v.size() - 1) {
         v[i] = v[i + 1];
         i++;
      }
      v.pop_back();
   } else {
      int i = v.size() / 2 - 1;
      while(i < v.size() - 2) {
         v[i] = v[i + 2];
         i++;
      }
      v.pop_back();
      v.pop_back();
   }
}

int main() {

   cout << endl;

   vector<string> vecteur_pair {"Cheval", "Koala", "Panda", "Chat", "Licorne"};
   imprimer_le_vecteur(vecteur_pair);
   supprimer_elements_centraux(vecteur_pair);
   imprimer_le_vecteur(vecteur_pair);

   cout << endl;

   vector<string> vecteur_impair {"Voiture", "Camion", "Avion", "Moto"};
   imprimer_le_vecteur(vecteur_impair);
   supprimer_elements_centraux(vecteur_impair);
   imprimer_le_vecteur(vecteur_impair);

   cout << endl;

return EXIT_SUCCESS;
}