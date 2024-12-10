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
private:
    double x, y;
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
    Point centre;
    centre.setX(0);
    centre.setY(0);
    centre.afficher();

    Point p;
    p.setX(1.2);
    p.setY(2.4);
    p.afficher();
    
    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;

    return 0;
}