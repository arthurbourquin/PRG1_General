// WIP

#include <iostream>
#include "coord-lib-Point.h"

int main() {

const Point<int> origin;

cout << "p1       : ";
Point<int> p1("p1"s);
p1.afficher();
cout << endl;

cout << "p2       : ";
Point<double> p2("p2"s, Coord(1.2, 3.4));
p2.afficher();
cout << endl;

cout << "p3       : ";
Point<double> p3("p3"s, 1.2, 3.4);
p3.afficher();
cout << endl;

cout << "p3.1     : ";
p3.setNom("p3.1"s);
p3.afficher();
cout << endl;

cout << "p1(-1, 1): ";
p1.setCoord(Coord(-1, 1));
p1.afficher();
cout << endl;

cout << "p1->     : ";
p1.deplacer(-1, 1);
p1.afficher();
cout << endl;

cout << "p1(x)    : ";
cout << p1.getNom() << " " << p1.getCoord().getX();

return EXIT_SUCCESS;
}