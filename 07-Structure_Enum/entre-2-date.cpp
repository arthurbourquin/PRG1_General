#include <iostream>
#include <iomanip>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void show_date(Date a) {
    cout << setfill('0') << setw(2) << a.day << "." << setw(2) << a.month << "." << setw(4) << a.year << endl;
}

bool isBissextile(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch(month){
        case 2: isBissextile(year) ? 29 : 28;
        case 1:;case 3:;case 5:;case 7:;case 8:;case 10:;case 12: return 31;
        default: return 30;
    }
}

int ddmmyyy_to_days(const Date& a) {
    int i = 0;
    int dateInDays = 0;
    while(i < a.year) {
        isBissextile(a.year) ? dateInDays += 366 : dateInDays += 365;
        i++;
    }
    dateInDays += daysInMonth(a.month, a.year);
    dateInDays += a.day;
    return dateInDays;
}

Date addDaysToYear(const Date& a, int numberOfDays) {
    int dateInDays = ddmmyyy_to_days(a);
    return {a.day + numberOfDays, a.month, a.year};
}

int main() {
    Date d1 = {0, 0, 0};
    Date d2 = {7, 5, 1986};

    cout << "date 1 : "; show_date(d1);
    cout << "date 2 : "; show_date(d2);
    cout << ddmmyyy_to_days(d2) - ddmmyyy_to_days(d1) << " jours séparent ces deux dates." << endl;

    return 0;
}