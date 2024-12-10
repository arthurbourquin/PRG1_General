#include <iostream>
using namespace std;

struct Point{
   double x, y;
   void afficher() const;
   void deplacer(double dx, double dy);
};

void Point::deplacer(double x, double y) {
   (*this).x += x;
   (*this).y += y;
}

void Point::afficher() const {
   cout << "(" << x << ", " << y << ")" << endl;
}

int main() {
   Point centre{};
   centre.afficher();

   Point p{1.2, 2.4};
   p.afficher();
   p.deplacer(0.8, 0.6);
   p.afficher();

   p.x = 5.5;
   p.y = 10.3;
   cout << p.x << " -- " << p.y << endl;

   return 0;
}