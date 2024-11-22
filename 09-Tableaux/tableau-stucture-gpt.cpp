#include <iostream>
#include <array>
using namespace std;

struct Date {
    uint8_t jour;
    uint8_t mois;
    uint16_t annee;
};

struct Personne {
    string prenom;
    string nom;
    Date date;
};

ostream& operator<<(ostream& os, const Date& date) {
    os << (int)date.jour << "/" << (int)date.mois << "/" << date.annee;
    return os;
}

array<Personne, 4> carnet{
    Personne{"Jean", "Veuxplus", Date{7, 4, 1975}},
    Personne{"Alain", "Verse", Date{21, 12, 2018}},
    Personne{"Justin", "Ptipeu", Date{1, 8, 2023}},
    Personne{"Rémi", "Fasol", Date{17, 5, 1957}}
};

Personne* ptr;
Personne& ref = carnet.at(0);

int main() {
    // Print ref.date
    cout << ref.date << endl;

    // Print ptr->date
    ptr = &carnet.at(0);
    cout << ptr->date << endl;

    // Modify ref.date and ptr->date
    ref.date.annee = 1976;
    ptr->date.annee = 1976;

    // Access second element in carnet
    cout << carnet.at(1).prenom[0] << carnet.at(1).nom[0] << endl;

    // Increment pointer and print
    ++ptr;
    cout << ptr->prenom[0] << ptr->nom[0] << endl;

    // Modify a string in carnet
    carnet.at(0).nom = "Un nom plus long pour agrandir le str";

    // Print sizes and addresses
    cout << "sizeof(Personne)     : " << sizeof(Personne) << endl;
    cout << "sizeof(Personne) x 4 : " << sizeof(Personne) * 4 << endl;
    cout << "sizeof(carnet)       : " << sizeof(carnet) << endl;

    cout << "carnet.data - debut  : " << carnet.data() << endl;
    cout << "carnet.data - fin    : " << carnet.data() + carnet.size() << endl;
    cout << "jean.nom.data        : " << (void*)(carnet.at(0).nom.data()) << endl;

    return EXIT_SUCCESS;
}
