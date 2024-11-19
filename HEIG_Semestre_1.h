#ifndef HEIG_SEMESTRE_1_H
#define HEIG_SEMESTRE_1_H

#include <string>

struct Cours {
    std::string module;
};

struct Etudiant {
    bool plein_temps;
    std::string cours;
};

void enseigner_PRG1(Etudiant &input, int cours);

#endif // HEIG_SEMESTRE_1_H
