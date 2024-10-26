#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string name;
int age;
double markMath;
double markPrg1;
double average;
bool accepted;
string question;
string invalidInputMessage = "Saisie invalide. ";
int cA = 10;
int cB = 10;
int cC = 15;
int cD = 10;

bool checkName() {
    bool result = true;
    string unallowedCharList = "0123456789:;<=>?@[]^_`{|}~";
    for(int i = 0; i < name.length() * unallowedCharList.length(); i++) {
        char userChar = name[i / unallowedCharList.length()];
        char unallowedChar = unallowedCharList[i % unallowedCharList.length()];
        if(userChar == unallowedChar) {
            result = false;
            break;
        }
    }
    return result;
}

double getValidValue(string question, double min, double max) {
    cout << question;
    double userInput;
    cin >> userInput;
    while(cin.fail() || userInput < min || userInput > max){
        cin.clear();
        cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Saisie incorrecte. " << question;
        cin >> userInput;
    }
    return userInput;
}

void printSeparationLine() {
    int width = cA + cB + cB + cC + cD;
    for(int i = 0; i < width; i++) {
        cout << '-';
    }
    cout << endl;
}

string returnAcceptance() {
    if(accepted == true) {
        return "Admis.e";
    } else {
        return "Rejeté.e";
    }
}

int main() {
    question = "Entrez le nom de l'étudiant : ";
    cout << question;
    getline(cin, name);
    while(!checkName()){
        cout << invalidInputMessage << question;
        cin >> name;    
    }
    age = getValidValue("Entrez l'âge de l'étudiant: ", 0, 100);
    markMath = getValidValue("Entrez la note de mathématique (max. 6): ", 0, 6);
    markPrg1 = getValidValue("Entrez la note de PRG1 (max. 6): ", 0, 6);
    average = (markMath + markPrg1) / 2;
    if(average > 3.75) {accepted = true;} else {accepted = false;}
    cout << setfill(' ');
    cout << setw(cA) << left << "Nom";
    cout << setw(cB) << right << "Age";
    cout << setw(cC) << right << "Note Math";
    cout << setw(cC) << right << "Note PRG1";
    cout << setw(cD) << right << returnAcceptance();
    cout << endl;
    printSeparationLine();
    cout << setw(cA) << left << name;
    cout << setw(cB) << right << fixed << setprecision(0) << age;
    cout << setw(cC) << right << fixed << setprecision(1) << markMath;
    cout << setw(cC) << right << fixed << setprecision(1) << markPrg1;
    cout << setw(cD) << right; if(accepted == true) {cout << "Oui";} else {cout << "Non";}
    cout << endl;
    printSeparationLine();
    cout << "Moyenne : " << fixed << setprecision(2) << average << endl;
    cout << "Résultat : " << returnAcceptance();
    cout << endl;

    return EXIT_SUCCESS;
}

/*
Entrez le nom de l'étudiant : Fouad Hanna
Entrez l'âge de l'étudiant : -5
Saisie invalide. Veuillez entrer un entier entre 1 et 100
f
Saisie invalide. Veuillez entrer un entier entre 1 et 100
21
Entrez la note en mathématiques (max. 6): -2
Saisie invalide. Veuillez entrer une valeur entre 1 et 6
s
Saisie invalide. Veuillez entrer une valeur entre 1 et 6
4.9
Entrez la note en PRG1 (max. 6): 33
Saisie invalide. Veuillez entrer une valeur entre 1 et 6
ee
Saisie invalide. Veuillez entrer une valeur entre 1 et 6
5.6
Nom               Age  Note Math     Note PRG1    Admis
-------------------------------------------------------
Fouad Hanna        21        4.9           5.6      Oui
-------------------------------------------------------
Moyenne : 5.25
Résultat : Admis
*/