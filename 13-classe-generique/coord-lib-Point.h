// WIP

#ifndef LIB_POINT
#define LIB_POINT

#include <iostream>
#include "coord-lib-Coord.h"
using namespace std;

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
      this->coord.afficher();
   }
   string getNom() {
      return this->nom;
   }
   Coord<T> getCoord() {
      return this->coord;
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
   // akfuaeh iauv aiuvn eoavuae vb eaivb 
   template<typename U>
   U distance(const Point & p) const {
      coord.distance(p.getCoord());
   }
};

#endif