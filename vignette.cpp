#include <iostream>
#include <string>
#include "HEIG_Semestre_1.h"

using namespace std;

Cours PRG1 = {"Introduction à la programmation"};
Etudiant HarryPotter = {true, ""};

void enseigner_PRG1(Etudiant &input, int cours) {
    input.cours += PRG1.module[cours];
}

int main() {
    enseigner_PRG1(HarryPotter, 1);
    cout << "Cours d'Harry Potter: " << HarryPotter.cours << endl;

    return EXIT_SUCCESS;
}
