#define STB_IMAGE_WRITE_IMPLEMENTATION // obligatoire
#include <algorithm>
#include <ctime>
#include <vector>
#include "stb_image_copy.h"
#include "stb_image_write_copy.h"

using namespace std;

#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(0, 255);
// use int r = dist(gen); to generate random number

void dessinerImage1(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR );

int main() {
    const unsigned LARGEUR = 256;
    const unsigned HAUTEUR = 256;
    unsigned char image[LARGEUR * HAUTEUR] = {}; // initialise l'image a zero (noir)

    for(int i= 0; i< LARGEUR*HAUTEUR; ++i) {
        image[i] = dist(gen);
//        image[i] = i % 256;
    }

    dessinerImage1(image, LARGEUR, HAUTEUR);
    stbi_write_bmp("Arthur.bmp", LARGEUR, HAUTEUR, 1, image); // enregistre l'image BMP

    return EXIT_SUCCESS;
}


void dessinerImage1(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR ) {}