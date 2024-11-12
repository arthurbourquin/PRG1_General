// WIP

#include <iostream>
using namespace std;

enum Jour {LU, MA, ME, JE, VE, SA, DI};

string shopping(int jour) {
    switch (jour) {
        case 1:; case 2:; case 3:; case 4:; case 5: return "Boulot"; break;
        case 6: return "Ouvert"; break;
        case 7: return "Fermé"; break;
        default: return "Pas un jour de la semaine..."; break;
    }
}

int main() {
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << shopping(i) << endl;
    }
    cout << endl;
}