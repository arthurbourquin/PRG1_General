#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string invalidInputMessage = "Saisie invalide. ";
int colA = 15;
int colB = 10;
int colC = 10;

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

bool checkIfInRange(double x, double min, double max) {
    if(x < min || x > max){
        return false;
    } else {
        return true;
    }
}

void printSeparationLine() {
    cout << "|";
    for(int i = 0; i < colA; i++) {cout << '-';}
    cout << "+";
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < colB; i++) {cout << '-';}
        cout << "+";
    }
    for(int i = 0; i < colC; i++) {cout << '-';}
    cout << "|";
    cout << endl;
}

string returnStudentAdmission(bool a, string gender) {
    string result;
    if(a == true) {
        result = "Admis";
    } else {
        result = "Rejeté";
    }

    if(gender == "F") {
        result += "e";
    } else if(gender == "X") {
        result += ".e";
    }

    return result;
}

string getUserString(string question, string requiredOneOfCharList, string forbiddenCharList) {
    string name;
    cout << question;
    getline(cin, name);
    while(shareElement(name, requiredOneOfCharList) && !shareElement(name, forbiddenCharList)){
        cout << invalidInputMessage << question;
        getline(cin, name);
    }
    return name;
}

double getUserReal(string question) {
    double result;
    cout << question;
    cin >> result;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Saisie incorrecte. " << question;
        cin >> result;
    }
    return result;
}


int main() {

    string name = getUserString("Entrez le nom de l'étudiant : ", "", "0123456789:;<=>?@[]^_`{|}~");
    if (name.length() > colA) {name = name.substr(0, colA - 3) + "...";}

    string gender = getUserString("Entrez le sexe (pas de mauvais jeux de mots S.V.P.) H ou F ou X : ", "HFX", "");

    double age = getUserReal("Entrez l'âge de l'étudiant: ");

    double markMath = getUserReal("Entrez la note de Math (max. 6): ");

    double markPrg1 = getUserReal("Entrez la note de PRG1 (max. 6): ");

    double average = (markMath + markPrg1) / 2;

    bool accepted;
    if(average > 3.75) {accepted = true;} else {accepted = false;}

    cout << setfill(' ');
    cout << "|";
    cout << setw(colA) << left << "Nom" << "|";
    cout << setw(colB) << right << "Age" << "|";
    cout << setw(colB) << right << "Math" << "|";
    cout << setw(colB) << right << "PRG1" << "|";
    cout << setw(colC) << right << returnStudentAdmission(true, gender) << "|";
    cout << endl;
    printSeparationLine();
    cout << "|";
    cout << setw(colA) << left << name << "|";
    cout << setw(colB) << right << fixed << setprecision(0) << age << "|";
    cout << setw(colB) << right << fixed << setprecision(1) << markMath << "|";
    cout << setw(colB) << right << fixed << setprecision(1) << markPrg1 << "|";
    cout << setw(colC) << right; if(accepted == true) {cout << "Oui";} else {cout << "Non";} cout << "|";
    cout << endl;
    printSeparationLine();
    cout << "Moyenne : " << fixed << setprecision(2) << average << endl;
    cout << "Résultat : " << returnStudentAdmission(accepted, gender);
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