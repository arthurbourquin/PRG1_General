#include <iostream>
#include <vector>
#include <numeric>
#include <ostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Vecteur {

    vector<T> v;

public:

    template <typename U>
    Vecteur(const vector<U> & vv):v(vv.begin(), vv.end())  {}

    friend ostream & operator << (ostream & os, const Vecteur & rhs) {
        os << "[";
        for(size_t i = 0; i < rhs.v.size(); ++i) {
            os << rhs.v[i] << (i != rhs.v.size() - 1 ? ", " : "");
        }
        return os << "]";
    }

    Vecteur & operator += (const Vecteur & rhs) {
        if(v.size() != rhs.v.size()) {
            throw invalid_argument("Taille incorrecte dans +=");
        }
        for(size_t i = 0; i < v.size(); ++i) {
            v[i] += rhs.v[i];
        }
        return *this;
    }

    Vecteur operator + (const Vecteur & rhs) const {
        Vecteur tmp = *this;
        return tmp += rhs;
    }

    Vecteur & operator *= (const T & a) {
        for(T & e : v) {
            e *= a;
        }
        return *this;
    }

    T operator * (const Vecteur & rhs) const {
        if(v.size() != rhs.v.size()) {
            throw invalid_argument("Taille incorrecte dans *=");
        }
        return inner_product(v.begin(), v.end(), rhs.v.begin(), T(0));
    }

    friend Vecteur operator * (Vecteur v, const T & a) {return v *= a;}
    friend Vecteur operator * (const T & a, Vecteur v) {return v *= a;}

    T & operator [] (size_t i) {return v.at(i);}
    T operator [] (size_t i) const {return v.at(i);}
};

int main() {

    vector<int> r{1,2,3,4}, t{1,2,3};
    const Vecteur<double> vr(r);
    Vecteur<int> vt(t);
    cout << fixed << vt << endl;
    cout << vr << endl;

    return 0;
}


/* Critères de correction
1 Inclusions
1 template class
2 constructeur (template + construction)
3 opérateur << (prototype, corps, retour)
5 opérateur += (prototype, vérification, exception, corps, retour)
2 opérateur + (prototype, corps utilisant += sur Vecteur)
2 opérateur *= (prototype, corps)
3 opérateur * (V * V: prototype, test, corps)
2 opérateur * (scalaire * V: prototype friend, corps)
1 opérateur * (V * scalaire)
4 opérateurs [] (prototype1, prototype2, corps, vérification)
Total 26 pts
*/

/*
Classe générique - 26 pts
Création d'une classe générique (26 pts)

On suppose que le type T dipose des opérateurs +et * à deux opérandes de type T, retournant une valeur du type T ainsi qu'un opérateur d'affichage <<.

Écrire une classe Vecteur, générique pour le type T, mettant à disposition:

    un constructeur à partir d'un vector (dont les éléments sont convertibles vers le type T)
    L'opérateur << permettant d'afficher le contenu d'un Vecteur (voir le format dans les exemples d'exécution)
    les opérateurs += et + qui font l'addition membre à membre de 2 Vecteur; si les opérandes n'ont pas la même taille, on lancera une exception appropriée
    un opérateur *= pour multiplier chaque membre du Vecteur à gauche par la valeur de type T à droite
    Les opérateurs * correspondants (T * Vecteur, Vecteur * T )
    un opérateur * retournant une valeur de type T correspondant au produit scalaire des 2 Vecteur-opérandes (somme des produits membre à membre)
    L'opérateur [], retournant un élément d'un Vecteur, avec vérification de l'indice (équivalent à la fonction-membre at() de vector)

Constructeur et opérateurs de la classe peuvent être définis en ligne.
*/