#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int a = 5;  // places au premier rang
    int r = 7;  // rangées
    int p = 50; // prix initial du billet
    int d = 5;  // .- de moins par rangée

    int t = 0; // total si plein

    int w = 5;
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= a; ++j) {
            int prix_de_la_place = p - d * (i - 1);
            t += prix_de_la_place;
            cout << setw(w) << setfill(' ') << prix_de_la_place;
        }
        for(int j = 1; j < i; ++j) {
            int prix_de_la_place = p - d * (i - 1);
            t += prix_de_la_place;
            cout << setw(w) << setfill(' ') << prix_de_la_place;
        }
        cout << endl;
    }
    cout << endl;
    cout << t << endl;
    cout << endl;

    return 0;
}