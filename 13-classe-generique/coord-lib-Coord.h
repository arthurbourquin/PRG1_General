// WIP

#ifndef LIB_COORD
#define LIB_COORD

#include <iostream>
#include <cmath>
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
   template<typename U>
   U distance(const Coord<T> & c) const {
      return sqrt(pow(x - c.getX(), 2) + pow(y - getY(), 2));
   }
};

#endif