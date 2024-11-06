#include <iostream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void show_date(Date a) {
    cout << a.day << "." << a.month << "." << a.year << endl;;
}

Date add_days(const Date& a, int numberOfDays) {
    return {a.day + numberOfDays, a.month, a.year};
}

int main() {
    Date d1;
    d1.day = 5;
    d1.month = 11;
    d1.year = 2024;

    Date d2 = {5, 11, 2024};
    
    show_date(d1); // 5.11.2024

    Date d3 = add_days(d1, 1);

    show_date(d3); // 6.11.2024

    return 0;
    
}