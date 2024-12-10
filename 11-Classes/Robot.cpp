#include <iostream>
using namespace std;

class Robot {
    int pos;
    bool sens;
public:
    void deplacer(int dist = 1) {dist > 0 ? (sens ? pos += dist : pos -= dist) : 0;}
    void faireDemiTour() {sens = !sens;}
    int getPosition() {return pos;}
    Robot(int init_pos) {pos = init_pos; sens = 1;}
    Robot(): Robot(0){}
};

int main() {
    Robot r1, r2(10);
    cout << "position courante de r2: " << r2.getPosition() << endl;
    r1.deplacer();
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(-1);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(2);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.faireDemiTour();
    r1.deplacer(4);
    cout << "position courante de r1: " << r1.getPosition() << endl;

    return EXIT_SUCCESS;
}