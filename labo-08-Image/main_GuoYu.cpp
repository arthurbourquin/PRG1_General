#define STB_IMAGE_WRITE_IMPLEMENTATION // obligatoire

#include <algorithm>
#include <ctime>
#include <vector>

#include "include/stb_image_write.h"
#include "lib/point.h"
#include "lib/segment.h"
#include "lib/triangle.h"
#include "lib/polygone.h"
#include "lib/cercle.h"

using std::vector;

void dessinerImage1(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR );
void dessinerImage2(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR );


int main() {
    const unsigned LARGEUR = 800;
    const unsigned HAUTEUR = 600;
    unsigned char image[LARGEUR * HAUTEUR] = {}; // initialise l'image a zero (noir)

    dessinerImage1(image, LARGEUR, HAUTEUR);
    stbi_write_bmp("image1.bmp", LARGEUR, HAUTEUR, 1, image); // enregistre l'image BMP

    // Vide le tableau
    // int 1 = 0;

    for(int i= 0; i< LARGEUR*HAUTEUR; ++i) {
        image[i] = i % 800;
    }

    dessinerImage2(image, LARGEUR, HAUTEUR);
    stbi_write_bmp("image2.bmp", LARGEUR, HAUTEUR, 1, image); // enregistre l'image BMP

    return EXIT_SUCCESS;
}


void dessinerImage1(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR ){
    /*
        * Image 1
        */
    // auto s1 = Segment(20, 30, 600, 40);
    // auto s2 = Segment(Point(100, 300), Point(0, 0));
    // auto s3 = Segment(10, 590, 790, 10);
    // s1.afficher(image, LARGEUR, HAUTEUR, 255);
    // s2.afficher(image, LARGEUR, HAUTEUR, 200);
    // s3.afficher(image, LARGEUR, HAUTEUR, 60);
    //
    // auto t1 = Triangle(Point(100, 400), Point(400, 100), Point(700, 400));
    // auto t2 = Triangle(Point(350, 150), Point(450, 150), Point(400, 200));
    // t1.afficherContour(image, LARGEUR, HAUTEUR, 190);
    // t2.afficherInterieur(image, LARGEUR, HAUTEUR, 250);
    //
    // auto c1 = Cercle(Point(150, 150), 200);
    // auto c2 = Cercle(Point(400, 300), 20);
    // c1.afficherContour(image, LARGEUR, HAUTEUR, 200);
    // c2.afficherInterieur(image, LARGEUR, HAUTEUR, 100);
    //
    //
    // auto poly1 = Polygone({Point(400, 500),
    //                        Point(400, 550),
    //                        Point(550, 550),
    //                        Point(425, 525),
    //                        Point(550, 250)});
    // poly1.afficherContour(image, LARGEUR, HAUTEUR, 100);

}

void dessinerImage2(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR ){
    /*
    * Image 2
    */
    const unsigned NB_CERCLES = 40;
    const unsigned RAYON_CERCLES = 40;

    // vector<Cercle> cercles;
    //
    // srand((unsigned) time(nullptr));
    // for (unsigned i = 0; i < NB_CERCLES;) {
    //     Cercle c(Point(int(rand() % (int) LARGEUR), int(rand() % (int) HAUTEUR)), RAYON_CERCLES);
    //     // si le cercle est dans l'image
    //     if (c.estDansImage(LARGEUR, HAUTEUR)) {
    //         bool disjoint = true;
    //         for (const auto &a : cercles) {
    //             // si les cercles se touchent, alors on sort de la boucle de test et on met disjoint à false
    //             if (!c.estDisjointsDe(a)) {
    //                 disjoint = false;
    //                 break;
    //             }
    //         }
    //         // si les cercles sont disjoints, alors on ajoute le cercle
    //         if (disjoint) {
    //             cercles.push_back(c);
    //             // on passe au prochain cercle
    //             ++i;
    //         }
    //     }
    // }
    //
    // // affichage des cercles avec une couleur aléatoire, mais pas trop foncée
    // for (const auto &c : cercles) {
    //     c.afficherInterieur(image, LARGEUR, HAUTEUR, (unsigned char) (rand() % 200 + 55));
    // }

}