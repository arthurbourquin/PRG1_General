#include <iostream>
#include <cstdlib>
#include <utility>
#include <iomanip>

using namespace std;

class Point {
   double pos_x, pos_y;
public:
   Point(double init_x, double init_y) {pos_x = init_x; pos_y = init_y;}
   double getX() const {return pos_x;}
   double getY() const {return pos_y;}
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
   Point p2(3., 4.2);

   cout << "p1" << p1 << ", p2" << p2 << endl;

   cout << "p1 + p2 = " << p1 + p2 << endl;
   cout << "p2 + p1 = " << p2 + p1 << endl;

   cout << "p1 * 2. = " << p1 * 2. << endl;
   cout << "3. * p1 = " << 3. * p1 << endl;

   cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
   Point p3(p1);
   cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;

   return 0;
}