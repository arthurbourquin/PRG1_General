// WIP... un peu à la ramasse
// surcharge des opérateurs

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>&) {
    os << "[";
    for(size_t i = 0; i < v.size(); ++i) {
        if(i) os << os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

// après il faut encore faire une fonction chais plus pk

int main() {
    using Line = vector<int>;
    using Matrice = vector<Line>;

    Line ligne1 {1, 2, 3};
}