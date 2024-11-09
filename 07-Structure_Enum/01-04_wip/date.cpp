#include <iostream>
#include "date.h"

void afficher_date(const Date &uneDate) {
    std::cout << uneDate.jour << "." << uneDate.mois << "." << uneDate.annee;
}