#include <iostream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void show_date(Date a) {
    cout << a.day << "." << a.month << "." << a.year << endl;
}

bool isBissextile(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400);
}

int daysInMonth(int month, int year) {
    switch(month){
        case 2: if(isBissextile(year)) {
                return 29;
            } else {
                return 28;
            }
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        default: return 30;
    }
}

int ddmmyyy_to_days(const Date& a) {
    int i = 0;
    int dateInDays = 0;
    while(i < a.year) {
        if(isBissextile(a.year)) {
            dateInDays += 366;
        } else {
            dateInDays += 365;
        }
        i++;
    }
    dateInDays += daysInMonth(a.month);
    dateInDays += a.day;
    return dateInDays;
}

Date addDaysToYear(const Date& a, int numberOfDays) {
    int dateInDays = ddmmyyy_to_days(a);
    return {a.day + numberOfDays, a.month, a.year};
}

int main() {
    Date d1;
    d1.day = 5;
    d1.month = 11;
    d1.year = 2024;
    
    show_date(d1);

    Date d2 = addDaysToYear(d1, 60);

    show_date(d2);

    return 0;
    
}