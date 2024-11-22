// SUCCESS

#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

using Date = array<int, 3>;

struct Person {
    string nom;
    string prenom;
    Date date;
};

string return_month(int month) {
    switch(month) {
        case 1: return "January"; 
        case 2: return "February"; 
        case 3: return "Mai"; 
        case 4: return "April"; 
        case 5: return "May"; 
        case 6: return "June"; 
        case 7: return "July"; 
        case 8: return "August"; 
        case 9: return "September"; 
        case 10: return "October"; 
        case 11: return "November"; 
        case 12: return "December"; 
        default: return "not a month"; 
    }
}

using PersonDatas = vector<Person>;

PersonDatas datas = {
    {"Jean"s, "Paul II"s, {7, 5, 1549}},
    {"Alain"s, "Delon"s, {3, 4, 1999}},
    {"Cassiopée"s, "Poubelle"s, {3, 12, 1987}},
    {"A"s, "C"s, {1, 1, 2000}}
};

string to_string(Date d) {
    return to_string(d[0]) + " " + return_month(d[1]) + " " + to_string(d[2]);
}

string to_string(Person p) {
    return p.nom + " " + p.prenom + " " + to_string(p.date) + "\n";    
}

string to_string(PersonDatas d) {
    string result = "";
    for(int i = 0; i < d.size(); i++) {
        result += to_string(d[i]) + "\n";
    }
    return result;
}

int main() {
    cout << endl;
    cout << to_string(datas) << endl;

    return 0; // Explicit exit status
}
