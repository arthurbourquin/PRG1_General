// SUCCESS

#include <iostream>
#include <iomanip>

using namespace std;

struct Date {
    int jour;
    int mois;
    int annee;
};

enum Mois {FAUX, JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC};

string nom_du_mois(Date d) {
    switch(d.mois) {
        case 1: return "janvier"; break;
        case 2: return "février"; break;
        case 3: return "mars"; break;
        case 4: return "avril"; break;
        case 5: return "mai"; break;
        case 6: return "juin"; break;
        case 7: return "juillet"; break;
        case 8: return "août"; break;
        case 9: return "septembre"; break;
        case 10: return "octobre"; break;
        case 11: return "novembre"; break;
        case 12: return "décembre"; break;
        default: return "OCTEMBRE?!"; break;
    }
}

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
    i = 0;
    while(i < a.mois) {
        dateInDays += jours_dans_le_mois(i, a.annee);
        i++;
    }
    dateInDays += a.jour;
    return dateInDays;
}

int interval_dates(const Date& dateDebut, const Date& DateFin) {
    return date_en_jours(DateFin) - date_en_jours(dateDebut);
}

void imprimer_interval(Date d1, Date d2) {
    cout <<
    
    "Entre le " << (d1.jour == 1 ? "1er" : to_string(d1.jour)) << " " <<
    nom_du_mois(d1) << " " <<
    (d1.annee < 1000 ? "de l'an " : "") << d1.annee <<

    " et le " << (d2.jour == 1 ? "1er" : to_string(d2.jour)) << " " <<
    nom_du_mois(d1) << " " <<
    (d2.annee < 1000 ? "de l'an " : "") << d2.annee <<

    " il y a " << interval_dates(d1, d2) << " jours." << endl;
}

int main() {
    Date d1 = {1, 1, 0000};
    Date d2 = {2, 1, 0000};
    Date d3 = {1, 1, 1986};
    Date dA = {7, 5, 1986};

    cout << "date 1 : "; imprimer_la_date(d3);
    cout << "date 2 : "; imprimer_la_date(dA);
    cout << "Année 2000 bissextile : " << est_bissextile(2000) << endl;
    cout << "Année 2001 bissextile : " << est_bissextile(2001) << endl;
    cout << "Jours en février 2000 : " << jours_dans_le_mois(2, 2000) << endl;
    cout << "Jours en février 2001 : " << jours_dans_le_mois(2, 2001) << endl;
    cout << "Jours en août 2000 : " << jours_dans_le_mois(8, 2000) << endl;
    cout << "0.0.000 en jours : " << date_en_jours(d1) << endl;
    cout << "Date 1 en jours : " << date_en_jours(d3) << endl;
    cout << "Date 2 en jours : " << date_en_jours(dA) << endl;
    cout << interval_dates(d3, dA) << " jours séparent ces deux dates." << endl;
    imprimer_interval(d1, d2);
    imprimer_interval(d1, d3);
    imprimer_interval(d2, d3);
    imprimer_interval(d1, dA);

    return 0;
}