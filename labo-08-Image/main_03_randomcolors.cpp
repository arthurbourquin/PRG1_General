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

void dessinerImage1(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR);

int main() {
    const unsigned LARGEUR = 256;
    const unsigned HAUTEUR = 256;
    unsigned char image[LARGEUR * HAUTEUR * 3] = {}; // Array for RGB image (3 channels)

    dessinerImage1(image, LARGEUR, HAUTEUR);
    stbi_write_bmp("image.bmp", LARGEUR, HAUTEUR, 3, image); // Save as BMP with 3 channels

    return EXIT_SUCCESS;
}

void dessinerImage1(unsigned char image[], unsigned LARGEUR, unsigned HAUTEUR) {
    for (unsigned y = 0; y < HAUTEUR; ++y) {
        for (unsigned x = 0; x < LARGEUR; ++x) {
            unsigned index = (y * LARGEUR + x) * 3;
            image[index] = dist(gen);        // Red channel
            image[index + 1] = dist(gen);   // Green channel
            image[index + 2] = dist(gen); // Blue channel
        }
    }
}