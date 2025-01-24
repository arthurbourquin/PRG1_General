#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

double f(double i, double j) {
    return i + j;
}

double double_somme(
    const string & nom_du_fichier, char serie_1, char serie_2,
    const size_t & i1, const size_t & in,
    const size_t & j1, const size_t & jn
    ) {
    ofstream file(nom_du_fichier + ".csv");

    double acc_serie_1 = 0;
    double acc_serie_2 = 0;
    for (int i = i1; i <= in; ++i) {
        acc_serie_2 = 0;
        for (int j = j1; j <= jn; ++j) {
            file << f(i, j);
            if(serie_2 == 'S') acc_serie_2 += f(i, j);
            if(serie_2 == 'P') acc_serie_2 *= f(i, j);
            if (j < jn) file << ',';
        }
        if(serie_1 == 'S') acc_serie_1 += acc_serie_2;
        if(serie_1 == 'P') acc_serie_1 *= acc_serie_2;
        file << endl;
    }
    file << acc_serie_1 << endl;
    file.close();

    return acc_serie_1;
}

int main() {
    double_somme("double-somme-4", 'S', 'P', 1, 3, 1, 3);
    return EXIT_SUCCESS;
}
