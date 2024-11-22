// WIP

#include <iostream>
#include <array>
using namespace std;

struct Date {
   uint8_t  jour;
   uint8_t  mois;
   uint16_t annee;
};

struct Personne {
   string prenom;
   string nom;
   Date   date;
};

array carnet {Personne{"Jean"s,   "Veuxplus"s, Date{ 7,  4, 1975}},
              Personne{"Alain"s,  "Verse"s,    Date{21, 12, 2018}},
              Personne{"Justin"s, "Ptipeu"s,   Date{ 1,  8, 2023}},
              Personne{"Rémi"s,   "Fasol"s,    Date{17,  5, 1957}}};

Personne* ptr;
Personne ref = carnet[0];

int main() {

   cout << carnet[0].date.jour;
   cout << ref.date.jour;

   ptr = &carnet.at(0);
   cout << ptr->date;

   ref.date.annee = 1976;

   ptr->date.annee = 1976;

   cout << (&ref + 1)->prenom[0] << (&ref + 1)->nom[0] << endl;

   ++ptr;
   cout << ptr->prenom[0] << ptr->nom[0] << endl;

   carnet.at(0).nom = "Un nom plus long pour agrandir le str";


   cout << "sizeof(Personne)     : " << sizeof(Personne)                   << endl;
   cout << "sizeof(Personne) x 4 : " << sizeof(Personne) * 4               << endl;
   cout << "sizeof(Carnet)       : " << sizeof(carnet)                     << endl;

   cout << "carnet.data - debut  : " << carnet.data()                      << endl;
   cout << "carnet.data - fin    : " << carnet.data() + carnet.size()      << endl;
   cout << "jean.nom.data        : " << (void*)(carnet.at(0).nom.data())   << endl;


return EXIT_SUCCESS;
}
