// WIP

#include <iostream>
#include <ostream>
// #include "coord.h"
using namespace std;

template<typename T>
class Coord {
   T x;
   T y;
public:
   Coord() : x(0), y(0) {};
   Coord(const T& initX, const T& initY) : x(initX), y(initY) {};
   T getX() const {return x;}
   T getY() const {return y;}
   void setCoord(T setX, T setY) {
      this->x = setX;
      this->y = setY;
   }
   void afficher() const {
      cout << "(" << x << ", " << y << ")" << endl;
   }
   void deplacer(const T& deltaX, const T& deltaY) {
      this->x += deltaX;
      this->y += deltaY;
   }
};

template<typename T>
class Point {
   string nom;
   Coord<T> coord;
public:
   Point() {}
   Point(string nom) {
      this->nom = nom;
      this->coord = Coord<T>();
   }
   Point(string nom, Coord<T> coord) {
      this->nom = nom;
      this->coord = coord;
   }
   Point(string nom, T x, T y) : Point(nom, Coord<T>(x, y)) {};
   void afficher() const {
      cout << this->nom;
      this->coord.afficher;
   }
   string getNom() {
      return this->nom;
   }
   Coord<T> getCoord() {

   }
   void setNom(string nom) {
      this->nom = nom;
   }
   void setCoord(const Coord<T>& coord) {
      this->coord = coord;
   }
   void deplacer(T x, T y) {
      this->coord.deplacer(x, y);
   }
};

int main() {

cout << "origine  : ";
const Coord<int> origin;
origin.afficher();
cout << endl;

cout << "p1       : ";
Coord<int> p1;
p1.setCoord(1, 2);
p1.afficher();
cout << endl;

cout << "p2       : ";
Coord<double> p2(3, 4);
p2.afficher();
cout << endl;

cout << "p2->     : ";
p2.deplacer(1, 1);   // conversion int => double
cout << "(" << p2.getX() << ", " << p2.getY() << ")";
cout << endl;

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