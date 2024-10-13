// WIP

#include <iostream>
#include <cmath>

using namespace std;

double balance = 500;
double amount = 0;

int withdrawal() {
    if(balance < 0) {        
        if(balance <= amount) {
            balance = balance - amount;
        } else {
            amount = balance;
            balance = 0;
        }
    } else {

    }
    cout << "Montant du retrait effectif = " << amount << endl;
    cout << "Solde courant = " << balance << endl;

    return 7;
}

int main() {

    cout << "Vous disposez de " << balance << endl;
    cout << "Vous voulez prendre du fric 'OUI' ou pas ? ";
    string userInput;
    cin >> userInput;
    if(userInput == "OUI") {
        cout << "Ok, combien : ";
        cin >> userInput;
        for(int i = 0; i < userInput.length(); i++ ){
            if( userInput[i] == '0' ||
                userInput[i] == '1' ||
                userInput[i] == '2' ||
                userInput[i] == '3' ||
                userInput[i] == '4' ||
                userInput[i] == '5' ||
                userInput[i] == '6' ||
                userInput[i] == '7' ||
                userInput[i] == '8' ||
                userInput[i] == '9') {
                    amount += (userInput[i] - '0') * pow(10, userInput.length() - i - 1);
                    cout << "amount: " << amount << " i: " << i << " l: " << userInput.length() << endl;
                }
            }
        withdrawal();
    } else {
        cout << "Pas compris... bye." << endl;
    }

    return EXIT_SUCCESS;
}