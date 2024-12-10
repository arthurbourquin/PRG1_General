// pas complet
// il faut texter les valeurs

#include <iostream>
using namespace std;

class Point{
public:
   void afficher() const;
   void deplacer(double dx, double dy);
   void setX(double x);
   void setY(double y);
   double getX() const;
   double getY() const;
   Point() : Point(0, 0, 0, 0) {}
   Point(double init_x, double init_y) :
      x(init_x), y(init_y) {}
   Point(double init_x, double init_y, double init_xMax, double init_yMax) :
      x(init_xMax), y(init_yMax), xMax(init_xMax), yMax(init_yMax) {}
private:
   double x, y, xMax, yMax;
};

double Point::getX() const {
   return x;
}

double Point::getY() const {
   return y;
}

void Point::setX(double x) {
   (*this).x = x;
}

void Point::setY(double y) {
   (*this).y = y;
}

void Point::deplacer(double x, double y) {
   (*this).x += x;
   (*this).y += y;
}

void Point::afficher() const {
   cout << "(" << x << ", " << y << ")" << endl;
}

int main() {
   Point p1(1.2, 2.4);
   cout << "p1"; p1.afficher();
   p1.deplacer(1., 3.);
   cout << "p1"; p1.afficher();
   p1.setX(4.);
   cout << "p1"; p1.afficher();
   p1.setY(7.);
   cout << "p1"; p1.afficher();

   Point p2(3., 4.2, 10., 10.);
   cout << "p2"; p2.afficher();
   p2.deplacer(15, 2);
   cout << "p2"; p2.afficher();
   p2.deplacer(3, 2);
   cout << "p2"; p2.afficher();
   p2.setX(-3);
   cout << "p2"; p2.afficher();
   p2.setY(12);
   cout << "p2"; p2.afficher();

   return 0;
}