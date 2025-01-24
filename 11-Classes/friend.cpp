#include <iostream>
using namespace std;

class Date {
private:
    int jour, mois, annee;
public :
    Date(int init_jour, int init_mois, int init_annee) :
        jour(init_jour), mois(init_mois), annee(init_annee) {}
    int getJour() const { return jour; }
    int getMois() const { return mois; }
    int getAnnee() const { return annee; }
    friend bool operator < (Date const & lhs, Date const & rhs);
    bool operator > (Date const & rhs) {
        return
            annee > rhs.annee ? true :
            mois > rhs.mois ? true :
            jour > rhs.jour;
    }
};

bool operator < (Date const & lhs, Date const & rhs) {
    return
        lhs.annee < rhs.annee ? true :
        lhs.mois < rhs.mois ? true :
        lhs.jour < rhs.jour;
}

// quelle différence ente une fonction externe amie et une fonction interne ??


int main() {

    Date anni(7, 5, 1986);
    Date ouais(1, 1, 1900);
    cout << endl;
    cout << (anni < ouais) << endl;
    cout << (ouais < anni) << endl;
    cout << endl;
    cout << (anni > ouais) << endl;
    cout << (ouais > anni) << endl;
    cout << endl;

    return 0;
}