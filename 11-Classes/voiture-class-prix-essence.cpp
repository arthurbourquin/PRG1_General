#include <iomanip>
#include <iostream>
using namespace std;

class Voiture {
public:
    Voiture(unsigned capaciteReservoir, double consommationMoyenne);

    unsigned getCapaciteReservoir() const { return capaciteReservoir; }
    double getConsommationMoyenne() const { return consommationMoyenne; }
    double getNbLitresDansReservoir() const { return nbLitresDansReservoir; }
    static double getPrixEssence() { return prixEssence; }

    static void setPrixEssence(double prix);

    double effectuerTrajet(double nbKm); // en valeur de retour : le coût du trajet
private:
    static double prixEssence;     // en Frs
    unsigned capaciteReservoir;    // en litres
    double consommationMoyenne;    // litres aux 100 km
    double nbLitresDansReservoir;  // nb de litres actuellement dans le réservoir
    static int vehiculesEnCirculation; // nb de véhicules en circulation
};

double Voiture::prixEssence = 1.7;
int Voiture::vehiculesEnCirculation = 0;

Voiture::Voiture(unsigned capaciteReservoir, double consommationMoyenne)
        : capaciteReservoir(capaciteReservoir),
          consommationMoyenne(consommationMoyenne),
          nbLitresDansReservoir(capaciteReservoir) { vehiculesEnCirculation++;
}

double Voiture::effectuerTrajet(double nbKm) {
   const double consommation = nbKm * consommationMoyenne / 100;
   nbLitresDansReservoir -= consommation;
   while (nbLitresDansReservoir <= 0)
      nbLitresDansReservoir += capaciteReservoir;
   return consommation * prixEssence;
}

void Voiture::setPrixEssence(double prix) {
   prixEssence = prix;
}

void afficherPrixEssence(double prix) {
   cout << fixed << setprecision(2)
        << "Prix de l'essence : " << prix << " Frs"
        << endl << endl << defaultfloat;
}

void afficherVoiture(const Voiture& v) {
   cout << "Capacite du reservoir [l]      : " << v.getCapaciteReservoir() << endl
        << fixed << setprecision(1)
        << "Consommation moyenne [l/100km] : " << v.getConsommationMoyenne() << endl
        << "Nb litres restants             : " << v.getNbLitresDansReservoir()
        << endl << endl << defaultfloat;
}

void afficherCoutTrajet(double montant) {
   cout << fixed << setprecision(2)
        << "Cout du trajet : " << montant << " Frs"
        << endl << endl << defaultfloat;
}

int main() {

   afficherPrixEssence(Voiture::getPrixEssence());

   Voiture::setPrixEssence(1.95);
   afficherPrixEssence(Voiture::getPrixEssence());

   Voiture v(52, 6.7);

   afficherVoiture(v);
   afficherCoutTrajet(v.effectuerTrajet(1000));
   afficherVoiture(v);
   afficherCoutTrajet(v.effectuerTrajet(200));
   afficherVoiture(v);
}