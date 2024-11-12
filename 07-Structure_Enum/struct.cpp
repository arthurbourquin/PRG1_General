// WIP

#include <iostream>

using namespace std;

struct OuaisLaDate {
    int jour;
    int mois;
    int annee;
};

OuaisLaDate Anni = {7, 5, 1986};

int main() {
    cout << "Arthur il est né le " << Anni.jour << " du " << Anni.mois << " en " << Anni.annee << endl;
}
