#include "lib.h"

using namespace std;

int main() {

    int i = saisir("Votre saisie", 0, 10);
    afficher("Votre saisie", i);

    return EXIT_SUCCESS;
}