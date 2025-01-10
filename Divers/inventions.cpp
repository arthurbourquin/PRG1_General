#include <iostream>
using namespace std;

class Invention {
    string nom;
    int annee;
public:
    string get_nom() const {return nom;}
    void set_nom(const string & init_nom) {nom = init_nom;}
    int get_annee() const {return annee;}
    void set_annee(int init_annee) {annee = init_annee;}
    Invention() : nom("Roue"), annee(-3456) {};
    Invention(const string & init_nom, int init_annee) :
    nom(init_nom), annee(init_annee) {};
    Invention & operator = (const Invention & rhs) {
        nom = rhs.get_nom();
        annee = rhs.get_annee();
        return *this;
    }
    Invention operator + (const Invention & rhs) {
        string tmp = nom.insert(nom.size() / 2, rhs.get_nom());
        tmp.insert(tmp.size() / 2, " de ");
        return Invention(
            tmp,
            annee =
                rhs.get_annee() != 0 ?
                annee % rhs.get_annee() / 7 :
                annee % (rhs.get_annee() + 7)
        );
    }
};

ostream & operator << (ostream & os, const Invention & i) {
    return os << "La \'" << i.get_nom() << "\' a été inventé à " << i.get_annee() << " de Jésus.";
}

int main() {

    Invention telephone("téléphone", 1876);
    Invention caca("caca", -647621);
    Invention Naruto("Naruto", 1999);

    cout << telephone << endl;
    cout << caca << endl;
    cout << Naruto << endl;

    cout << (telephone + Naruto) << endl;
    cout << (Naruto + caca) << endl;
    cout << (caca + Naruto + telephone) << endl;
    cout << (telephone + caca + Naruto) << endl;

    return 0;
}