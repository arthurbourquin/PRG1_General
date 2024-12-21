// WIP

#include <iostream>
#include <cmath>

using namespace std;

class Point {
   double pos_x, pos_y, min, max, index;
   static int pointNumber;
public:
   Point(double init_x, double init_y, double min_val = 0, double max_val = 100) {
      init_x < min_val ? pos_x = min_val : (init_x > max_val ? max_val : init_x);
      init_y < min_val ? pos_y = min_val : (init_y > max_val ? max_val : init_y);
   }
   double getX() const {return pos_x;}
   double getY() const {return pos_y;}
   void afficher() {cout << "position courante de " << index << " : (" << pos_x << ", " << pos_y << ")" << endl;}
   static int getNbPoints() {return pointNumber;}
};

ostream& operator<< (ostream& os, const Point& p) {
   os << "(" << p.getX() << ", " << p.getY() << ")";
   return os;
};

Point operator+ (const Point& p1, const Point& p2) {
   return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
};

Point operator* (const Point& p, double d) {
   return Point(p.getX() * d, p.getY() * d);
};

Point operator* (double d, const Point& p1) {
   return p1 * d;
};

bool operator== (const Point& p1, const Point& p2) {
   return p1.getX() == p2.getX() && p1.getY() == p2.getY();
};

int main() {

   Point p1(1.2, 2.4);
   p1.afficher();

   cout << "Nombre de points : " << Point::getNbPoints() << endl;
   cout << "-------------------------------------------" << endl;

   {
      Point p2(3., 4.2, 10., 10.);
      p2.afficher();

      cout << "Nombre de points : " << Point::getNbPoints() << endl;
      cout << "-------------------------------------------" << endl;

      p2 = p1;
      p2.afficher();

      cout << "Nombre de points : " << Point::getNbPoints() << endl;
      cout << "-------------------------------------------" << endl;

      Point p3 = p2;
      p3.afficher();

      cout << "Nombre de points : " << Point::getNbPoints() << endl;
      cout << "-------------------------------------------" << endl;
   }

   Point p4(5, 10);
   p4.afficher();

   cout << "Nombre de points : " << Point::getNbPoints() << endl;
   cout << "-------------------------------------------" << endl;
}