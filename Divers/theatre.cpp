#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double a = 10;  // places au premier rang
    double r = 10;  // rangées
    double p = 95; // prix initial du billet
    double d = 6;  // .- de moins par rangée

    cout << endl;
    cout << endl;
    cout << "LE THEATRE" << endl;
    cout << endl;
    cout << "Avec pour " << a << " places au premier rang qui coûtent " << p << " francs et pis après y a un siège de plus à chaque rangées pour " << r << " rangées où c'que chaque rangée c'est " << d << ".- de moins, ça fait :" << endl;
    cout << endl;

    double t = 0; // total si plein

    double w = 5;  // largeur de l'affichage
    for (int i = 1; i <= r; ++i) {
        double prix_de_la_place = p - d * (i - 1);
        for (int j = 1; j <= (a + i - 1); ++j) { // le nombre de places augmente par rangée
            t += prix_de_la_place;
            cout << setw(w) << setfill(' ') << prix_de_la_place;
        }
        cout << endl;
    }

    cout << endl;
    cout << "Recette totale si salle comble :" << endl;
    cout << endl;
    cout << "algo:    " << t << endl;
    // arthur
    double apr = a * p * r;
    double i = (p - 5 * a) * (r * (r - 1) / 2.0);
    double ii = -(d / 6.0) * (r + 1) * r * (2 * r + 1);
    double merde = -5.0 * r * r * r;
    cout << "arthur:  " << apr + i + ii + merde<< endl;
    // gpt
    double sum1 = a * p * r;
    double sum2 = d * a * (r - 1) * r / 2.0;
    double sum3 = p * (r - 1) * r / 2.0;
    double sum4 = d * (r - 1) * r * (2 * r - 1) / 6.0;
    cout << "gpt:     " << sum1 - sum2 + sum3 - sum4 << endl;
    // robin
    double r2 = r - 1;
    double sum_i = r2 * (r2 + 1) / 2.0;
    double sum_ii = r2 * (r2 + 1) * (2 * r2 + 1) / 6.0;
    cout << "robin:   " << (r2+1) * a * p - d * a * sum_i + sum_i * p - d * sum_ii << endl;
    return 0;
}