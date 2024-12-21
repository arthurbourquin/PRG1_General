#include <iostream>
#include <string>
using namespace std;


class Troll {
private:
    string kink;
    static int nb;
    friend void trollInfo(const Troll& obj);
public:
    string name;
    Troll(string init_kink, const string& init_name) 
        : kink(init_kink), name(init_name) {
            nb++;
        }
    Troll()
        : Troll("BDSM", "Rocky " + to_string(nb)) {}
    void setKink(const string& newKink) {
        kink = newKink;
    }
    string getKink() const {
        return kink;
    }
    static void addTroll() {
        nb++;
    }
    static int getNb() {
        return nb;
    }
};


int Troll::nb = 0;

void trollInfo(const Troll& obj) {
    string s = "s"; if(obj.nb <= 1) {s = "";}
    cout << obj.name << ", one of " << obj.nb << " gentle troll" << s << ", likes " << obj.kink << "." << endl;
}

int main() {

    Troll t1;
    trollInfo(t1);
    Troll t2;
    trollInfo(t2);
    Troll t3;
    trollInfo(t3);
    Troll Moutarde("Cluedo", "Moutarde");
    trollInfo(Moutarde);
    Troll Georges("Chess", "Georges");
    trollInfo(Georges);
    Troll Jake("Vagina", "Jake");
    trollInfo(Jake);
    Troll Tinkiwinkie("Sodomie", "Titi");
    trollInfo(Tinkiwinkie);

    return 0;
}