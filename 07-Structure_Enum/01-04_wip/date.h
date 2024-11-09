#ifndef DATE_H
#define DATE_H

struct Date {
    int jour;
    int mois;
    int annee;
};

void afficher_date(const Date& uneDate);

#endif