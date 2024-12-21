#define STB_IMAGE_WRITE_IMPLEMENTATION // obligatoire

#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include "stb_image_copy.h"
#include "stb_image_write_copy.h"

using namespace std;
using std::vector;

void dessinerImage1(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR );
void dessinerImage2(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR );

class Point {
    int x, y;
public:
    Point(int x, int y) 
        : x{x},y{y} {}
};

class Segment {
private:
    Point A, B;
public:
    Segment(int Ax, int Ay, int Bx, int By) 
        : A{Ax, Ay}, B{Bx, By} {}
    Segment(Point A, Point B)
        : A{A}, B{B} {}
    void afficher(unsigned char image[], const unsigned largeur, const unsigned hauteur, unsigned char jemetsopacitemaisjesaispascequecest) {
        for(int i = 0; i < (largeur -1) * (hauteur - 1); ++i) {
            image[i] * jemetsopacitemaisjesaispascequecest;
        }
    }
};

class Triangle {
    Point A, B, C;

}

int main() {
    const unsigned LARGEUR = 800;
    const unsigned HAUTEUR = 600;
    unsigned char image[LARGEUR * HAUTEUR] = {}; // initialise l'image a zero (noir)

    dessinerImage1(image, LARGEUR, HAUTEUR);
    stbi_write_bmp("image1.bmp", LARGEUR, HAUTEUR, 1, image); // enregistre l'image BMP

    // Vide le tableau
    for (unsigned char &c : image) {
        c = 0;
    }

    dessinerImage2(image, LARGEUR, HAUTEUR);
    stbi_write_bmp("image2.bmp", LARGEUR, HAUTEUR, 1, image); // enregistre l'image BMP

    return EXIT_SUCCESS;
}

void dessinerImage1(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR ){
    /*
        * Image 1
        */
    auto s1 = Segment(20, 30, 600, 40);
    auto s2 = Segment(Point(100, 300), Point(0, 0));
    auto s3 = Segment(10, 590, 790, 10);
    s1.afficher(image, LARGEUR, HAUTEUR, 255);
    s2.afficher(image, LARGEUR, HAUTEUR, 200);
    s3.afficher(image, LARGEUR, HAUTEUR, 60);

    auto t1 = Triangle(Point(100, 400), Point(400, 100), Point(700, 400));
    auto t2 = Triangle(Point(350, 150), Point(450, 150), Point(400, 200));
    t1.afficherContour(image, LARGEUR, HAUTEUR, 190);
    t2.afficherInterieur(image, LARGEUR, HAUTEUR, 250);

    auto c1 = Cercle(Point(150, 150), 200);
    auto c2 = Cercle(Point(400, 300), 20);
    c1.afficherContour(image, LARGEUR, HAUTEUR, 200);
    c2.afficherInterieur(image, LARGEUR, HAUTEUR, 100);


    auto poly1 = Polygone({Point(400, 500),
                           Point(400, 550),
                           Point(550, 550),
                           Point(425, 525),
                           Point(550, 250)});
    poly1.afficherContour(image, LARGEUR, HAUTEUR, 100);

}

void dessinerImage2(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR ){
    /*
    * Image 2
    */
    const unsigned NB_CERCLES = 40;
    const unsigned RAYON_CERCLES = 40;

    vector<Cercle> cercles;

    srand((unsigned) time(nullptr));
    for (unsigned i = 0; i < NB_CERCLES;) {
        Cercle c(Point(int(rand() % (int) LARGEUR), int(rand() % (int) HAUTEUR)), RAYON_CERCLES);
        // si le cercle est dans l'image
        if (c.estDansImage(LARGEUR, HAUTEUR)) {
            bool disjoint = true;
            for (const auto &a : cercles) {
                // si les cercles se touchent, alors on sort de la boucle de test et on met disjoint à false
                if (!c.estDisjointsDe(a)) {
                    disjoint = false;
                    break;
                }
            }
            // si les cercles sont disjoints, alors on ajoute le cercle
            if (disjoint) {
                cercles.push_back(c);
                // on passe au prochain cercle
                ++i;
            }
        }
    }

    // affichage des cercles avec une couleur aléatoire, mais pas trop foncée
    for (const auto &c : cercles) {
        c.afficherInterieur(image, LARGEUR, HAUTEUR, (unsigned char) (rand() % 200 + 55));
    }

}