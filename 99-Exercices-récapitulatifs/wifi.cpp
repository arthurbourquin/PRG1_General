#include <iostream>
#include <vector>

using namespace std;

struct Routeur {
    int intensiteSignal; // Intensité du signal du routeur
    Routeur(int init) : intensiteSignal(init) {}
};

using Reseau = vector<vector<Routeur>>;

Reseau consoliderSignal(Reseau r) {
    Reseau result((r.size() + 1 ) / 2, vector<Routeur>(2, 0));
    size_t i = 0;
    size_t row = 0;
    size_t col = 0;
    while(true) {
        if(row >= r.size()) break;
        if(row + 1 < r.size()) {
            result.at(row / 2).at(col / 2).intensiteSignal += r.at(row).at(col).intensiteSignal;
        } else {
            result.at(row / 2).at(col / 2).intensiteSignal += r.at(row).at(col).intensiteSignal * 2;
        }
    ++i;
    row = i / 4;
    col = i % 4;
    }
    for(size_t k = 0; k < result.size(); ++k) {
        for(size_t l = 0; l < 2; ++l) {
            result.at(k).at(l).intensiteSignal /= 4;
        }
    }
    return result;
}


Reseau consoliderSignal_old1(Reseau r) {
    Reseau result((r.size() +1 ) / 2, vector<Routeur>(4, 0));
    for(size_t i = 0; i < r.size(); ++i) {
        result.at(i / 2).at(0).intensiteSignal += r.at(i).at(0).intensiteSignal + r.at(i).at(1).intensiteSignal; 
        result.at(i / 2).at(1).intensiteSignal += r.at(i).at(0).intensiteSignal + r.at(i).at(1).intensiteSignal;
    }
    return result;
}

int main() {
    Reseau reseau = {
            {{90}, {80}, {70}, {60}},
            {{80}, {70}, {60}, {50}},
            {{70}, {60}, {50}, {40}},
            {{60}, {50}, {40}, {30}},
            {{50}, {40}, {30}, {20}}
    };

    Reseau nouveauReseau = consoliderSignal(reseau);

    // Imprimer le nouveau réseau
    for (size_t i = 0; i < nouveauReseau.size(); i++) {
        for (size_t j = 0; j < nouveauReseau[i].size(); j++) {
            std::cout << nouveauReseau[i][j].intensiteSignal << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}