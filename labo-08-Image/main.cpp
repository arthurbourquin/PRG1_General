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

bool XOR(bool A, bool B) {
    return (A + B == 1);
}

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
    int index = 0;
    for (unsigned y = 0; y < HAUTEUR; ++y) {
        for (unsigned x = 0; x < LARGEUR; ++x) {
            unsigned char current_value = XOR(x % 32 < 16, y % 32 < 16) ? 0 : 255;
            image[index * 3 + 0] = current_value;
            image[index * 3 + 1] = current_value;
            image[index * 3 + 2] = current_value;
            index++;
        }
    }
}