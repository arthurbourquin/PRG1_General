#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

// Fonction pour afficher l'état de la mémoire avec des types différents
void inspectMemory(void* address, size_t size, const string& typeName) {
    unsigned char* bytePtr = reinterpret_cast<unsigned char*>(address);

    cout << "\nInspecting memory of type: " << typeName << " at address: " << address << endl;

    // Affichage de la mémoire en hexadécimal
    for (size_t i = 0; i < size; ++i) {
        cout << "Address: " << static_cast<void*>(bytePtr + i) 
             << " | Value (hex): " << hex << setw(2) << setfill('0') << (int)*(bytePtr + i) 
             << " | Value (char): ";
        
        // Affichage en tant que caractère si imprimable
        if (isprint(*(bytePtr + i))) {
            cout << "'" << *(bytePtr + i) << "'";
        } else {
            cout << "(non-printable)";
        }
        cout << endl;
    }

    // Affichage du type
    if (typeName == "int") {
        cout << "As int: " << *reinterpret_cast<int*>(address) << endl;
    }
    else if (typeName == "double") {
        cout << "As double: " << *reinterpret_cast<double*>(address) << endl;
    }
    else if (typeName == "float") {
        cout << "As float: " << *reinterpret_cast<float*>(address) << endl;
    }
}

int main() {
    // Déclaration de quelques variables
    int number = 42;
    double pi = 3.14159;
    float piFloat = 3.14f;
    char text[] = "Hello";

    // Affichage de l'état de la mémoire pour chaque variable
    cout << "Variables initialisées :" << endl;
    cout << "number: " << number << " (address: " << &number << ")" << endl;
    cout << "pi: " << pi << " (address: " << &pi << ")" << endl;
    cout << "piFloat: " << piFloat << " (address: " << &piFloat << ")" << endl;
    cout << "text: " << text << " (address: " << static_cast<void*>(text) << ")" << endl;

    // Inspection des données
    inspectMemory(&number, sizeof(number), "int");
    inspectMemory(&pi, sizeof(pi), "double");
    inspectMemory(&piFloat, sizeof(piFloat), "float");
    inspectMemory(text, strlen(text) + 1, "char[]");
    
    return 0;
}
