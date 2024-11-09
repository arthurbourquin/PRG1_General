#include <iostream>

using namespace std;

enum class Direction {HAUT, BAS, GAUCHE, DROITE};

struct Coord {
    int x = 0;
    int y = 0;
};

using Point = Coord;

void deplacer(Point& p, Direction dir) {
    switch(dir) {
        case Direction::BAS: p.y--; break;
        case Direction::HAUT: p.y++; break;
        case Direction::DROITE: p.x++; break;
        case Direction::GAUCHE: p.x--; break;
    }
}

int main() {
    Point p = {0, 0};
}
