#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Troll {
private:
    int exitation;                              // spécifique   variable
    const string couleur;                       // spécifique   constant
    static string emotion;                      // global       variable
    static vector<string> couleurs;             // global       variable
    static const array<string, 5> emotions;     // global       constant
    static int nombre;                          // global       variable
public:
    Troll() : exitation(10 + rand() % 5), couleur(couleurs[rand() % couleurs.size()]) {nombre++;}
    ~Troll() {nombre--;}
    int get_excitation() const {return exitation;}
    string get_couleur() const {return couleur;}
    string get_emotion() const {return emotion;}
    int set_exitation(int new_exitation) {exitation = new_exitation;}
    static string set_emotion(string new_emotion) {
        for(int i = 0; i < emotions.size(); ++i) {
            if(new_emotion == emotions.at(i)) {
                emotion = new_emotion;
                break;
            }
        }
    }
    void ajouter_couleur(string new_couleur) {
        couleurs.push_back(new_couleur);
    }
    void supprimer_couleur(string a_supprimer) {
        for(int i = 0; i < couleurs.size(); ++i) {
            if(a_supprimer == couleurs.at(i)) {
                couleurs.erase(couleurs.begin() + i);
                break;
            }
        }
    }
};

const array<std::string, 5> Troll::emotions = {"Joyeux", "Triste", "Fâché", "Inquiet"};
vector<string> Troll::couleurs = {"rose", "cyan", "violet"};