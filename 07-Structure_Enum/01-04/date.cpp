#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstdlib>

struct Date {
    int jour;
    int mois;
    int annee;
};

void afficher_date(Date uneDate) {
    std::cout << uneDate.jour << "." << uneDate.mois << "." << uneDate.annee;
}

#endif