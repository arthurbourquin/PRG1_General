#include <iostream>
#include <iomanip>

using namespace std;

struct Date {
    int jour;
    int mois;
    int annee;
};

void imprimer_la_date(Date a) {
    cout << setfill('0') << setw(2) << a.jour << "." << setw(2) << a.mois << "." << setw(4) << a.annee << endl;
}

bool est_bissextile(int annee) {
    return ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0);
}

int jours_dans_le_mois(int mois, int annee) {
    switch(mois){
        case 2: return est_bissextile(annee) ? 29 : 28; break;
        case 1:;case 3:;case 5:;case 7:;case 8:;case 10:;case 12: return 31; break;
        default: return 30;
    }
}

int date_en_jours(const Date& a) {
    int i = 0;
    int dateInDays = 0;
    while(i < a.annee) {
        est_bissextile(a.annee) ? dateInDays += 366 : dateInDays += 365;
        i++;
    }
    dateInDays += jours_dans_le_mois(a.mois, a.annee);
    dateInDays += a.jour;
    return dateInDays;
}

int intervalEntreDeuxDates(const Date& dateDebut, const Date& DateFin) {
    return date_en_jours(DateFin) - date_en_jours(dateDebut);
}

int main() {
    Date d1 = {0, 0, 1986};
    Date d2 = {7, 5, 1986};

    cout << "date 1 : "; imprimer_la_date(d1);
    cout << "date 2 : "; imprimer_la_date(d2);
    cout << intervalEntreDeuxDates(d1, d2) << " jours séparent ces deux dates." << endl;

    return 0;
}