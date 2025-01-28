#include <iostream>
#include <cassert>
#include <vector>
#include <stdexcept>
using namespace std;

struct Color {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    Color(unsigned char iR, unsigned char iG, unsigned char iB) :
        R(iR), G(iG), B(iB) {}
};

struct Coord {
    size_t x;
    size_t y;
    static const Coord origin;
    Coord(size_t ix, size_t iy) : x(ix), y(iy) {}
};

class Image {
    size_t w;
    size_t h;
    vector<Color> colors;
    Image(size_t init_w, size_t init_h, Color init_col) :
        w(init_w), h(init_h) {
            for(size_t i = 0; i < w * h; ++i) {
                colors.push_back(init_col);
            }
        }
public:
    size_t getw() {return w;}
    size_t geth() {return h;}
    bool isInImage(Coord c) {
        if(c.x < 0 || c.x > w || c.y < 0 || c.y > h) return false;
        return true;
    }
    Color getcol(Coord coord) {
        if(!isInImage(coord))
            throw out_of_range("coordonnée en dohors de l'image");
        return colors.at(coord.x + w * coord.y);
        }
    Image subImage(Coord c, size_t new_w, size_t new_h) {
        if(!isInImage(c))
            throw out_of_range("coordonnée en dohors de l'image");
        if(!isInImage(Coord(c.x + w, c.y + h)))
            throw out_of_range("subImage en dehors de l'image");
        Image result(new_w, new_h, Color(0, 0, 0));
        for(size_t i = 0; i < new_w; ++i) {
            for(size_t j = 0; j < new_h; ++j) {
                result.colors.at(i + new_w * j) = 
                colors.at(j + c.x + w * (c.y + i));
            }
        }
    }
};

const Coord Coord::origin{};

int main() {

   Color cyan{0, 255, 255};
   cout << "cyan codé comme (" << +cyan.R << "," << +cyan.G << "," << +cyan.B << ")" << endl;

   Coord p{10, 20};
   cout << "p(" << p.x << "," << p.y << ")" << endl;
   cout << "origin(" << Coord::origin.x << "," << Coord::origin.y << ")" << endl;

   Color black{0,0,0};
   Image imageHD(1280, 720, black);
   cout << "Image HD de taille " << imageHD.getw() << "x" << imageHD.geth() << endl;
   cout << "La composante G du pixel de coordonnée p est " << +imageHD[p].G << endl;

   imageHD[p] = cyan;
   cout << "La composante G du pixel de coordonnée p est " << +imageHD[p].G << endl;

   Image sub = imageHD.subImage(p,20,10);
   cout << "sub de taille " << sub.getw() << "x" << sub.geth() << endl;

   cout << "La composante B du pixel en (0,0) est " << +sub[Coord::origin].B << endl;
}