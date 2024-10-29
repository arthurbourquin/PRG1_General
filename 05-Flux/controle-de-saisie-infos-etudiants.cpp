#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string name;
string unallowedCharForName = "0123456789:;<=>?@[]^_`{|}~";
string gender;
string allowedCharForGender = "HFX";
int age;
double markMath;
double markPrg1;
double average;
bool accepted;
string question;
string invalidInputMessage = "Saisie invalide. ";
int cA = 15;
int cB = 10;
int cC = 10;

void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

bool shareElement(string A, string B) {
    bool result = true;
    for(int i = 0; i < A.length() * B.length(); i++) {
        char a = A[i / B.length()];
        char b = B[i % B.length()];
        if(a == b) {
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Saisie incorrecte. Veuillez entrer un nombre entre " << fixed << setprecision(0) << min << " et " << setprecision(0) << max << " : ";
        cin >> userInput;
    }
    clearCin();
    return userInput;
}

void printSeparationLine() {
    cout << "|";
    for(int i = 0; i < cA; i++) {cout << '-';}
    cout << "+";
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < cB; i++) {cout << '-';}
        cout << "+";
    }
    for(int i = 0; i < cC; i++) {cout << '-';}
    cout << "|";
    cout << endl;
}

string returnAcceptance(bool a, string g) {
    string result;
    if(a == true) {
        result = "Admis";
    } else {
        result = "Rejeté";
    }

    if(g == "F") {
        result += "e";
    } else if(g == "X") {
        result += ".e";
    }

    return result;
}

void getName() {
        question = "Entrez le nom de l'étudiant : ";
    cout << question;
    getline(cin, name);
    while(!shareElement(name, unallowedCharForName)){
        cout << invalidInputMessage << question;
        getline(cin, name);
    }
    if (name.length() > cA) {
        name = name.substr(0, cA - 3) + "...";
    }
}
void getGender() {
    question = "Entrez le sexe (pas de mauvais jeux de mots S.V.P.) H ou F ou X : ";
    cout << question;
    cin >> gender;
    while(gender.length() == 1 && shareElement(gender, allowedCharForGender)){
        cout << invalidInputMessage << question;
        cin >> gender;    
    }
    clearCin();
}
int main() {

    getName();
    getGender();
    age = getValidValue("Entrez l'âge de l'étudiant: ", 0, 100);
    markMath = getValidValue("Entrez la note de mathématique (max. 6): ", 0, 6);
    markPrg1 = getValidValue("Entrez la note de PRG1 (max. 6): ", 0, 6);
    average = (markMath + markPrg1) / 2;
    if(average > 3.75) {accepted = true;} else {accepted = false;}

    cout << setfill(' ');
    cout << "|";
    cout << setw(cA) << left << "Nom" << "|";
    cout << setw(cB) << right << "Age" << "|";
    cout << setw(cB) << right << "Math" << "|";
    cout << setw(cB) << right << "PRG1" << "|";
    cout << setw(cC) << right << returnAcceptance(true, gender) << "|";
    cout << endl;
    printSeparationLine();
    cout << "|";
    cout << setw(cA) << left << name << "|";
    cout << setw(cB) << right << fixed << setprecision(0) << age << "|";
    cout << setw(cB) << right << fixed << setprecision(1) << markMath << "|";
    cout << setw(cB) << right << fixed << setprecision(1) << markPrg1 << "|";
    cout << setw(cC) << right; if(accepted == true) {cout << "Oui";} else {cout << "Non";} cout << "|";
    cout << endl;
    printSeparationLine();
    cout << "Moyenne : " << fixed << setprecision(2) << average << endl;
    cout << "Résultat : " << returnAcceptance(accepted, gender);
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





Nom         Age      Math      PRG1   Admis.e
----------------------------------------
wugfs o...    4       4.0       4.0       Oui
----------------------------------------
*/