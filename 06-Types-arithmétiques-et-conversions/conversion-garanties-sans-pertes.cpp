#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <limits> // Required for numeric_limits
using namespace std;

int l1 = 30;
int l2 = 2;
int tmp;

int main() {
    cout << endl;
    cout << setfill(' ');

    tmp = static_cast<int>(log2(numeric_limits<char>::max()));
    cout << "ouais ? " << static_cast<int>(numeric_limits<char>::max()) << endl;
    cout << "ouais ? " << static_cast<int>(numeric_limits<char>::max() + 1) << endl;
    cout << "ouais ? " << static_cast<int>(log2(numeric_limits<char>::max())) << endl;
    cout << "ouais ? " << static_cast<int>(log2(numeric_limits<char>::max() + 1)) << endl;
    cout << setw(l1) << left << "char" << endl;
    cout << "max = 2^";
    cout << setw(l2) << to_string(tmp);
    cout << " = " << fixed << setprecision(log10(tmp) - 1) << pow(2, tmp);
    cout << endl;
    cout << endl;

    cout << setw(l1) << left << "short" << endl;
    cout << tmp << endl;
    cout << "max = 2^";
    tmp = static_cast<int>(log2(numeric_limits<short>::max()));
    cout << setw(l2) << to_string(tmp);
    cout << " = " << fixed << setprecision(log10(tmp) - 1) << pow(2, tmp);
    cout << endl;
    cout << endl;

    cout << setw(l1) << left << "int" << endl;
    cout << tmp << endl;
    cout << "max = 2^";
    tmp = static_cast<int>(log2(numeric_limits<int>::max()));
    cout << setw(l2) << to_string(tmp);
    cout << " = " << fixed << setprecision(log10(tmp) - 1) << pow(2, tmp);
    cout << endl;
    cout << endl;

    cout << setw(l1) << left << "long long int" << endl;
    cout << tmp << endl;
    cout << "max = 2^";
    tmp = static_cast<int>(log2(numeric_limits<long long int>::max()));
    cout << setw(l2) << to_string(tmp);
    cout << " = " << fixed << setprecision(log10(tmp) - 1) << pow(2, tmp);
    cout << endl;
    cout << endl;

    cout << setw(l1) << "float digits =  2^";
    cout << setw(l1) << to_string(numeric_limits<float>::digits) << endl;
    cout << setw(l1) << "float digits = 10^";
    cout << setw(l1) << to_string(numeric_limits<float>::digits10) << endl;
    cout << endl;

    cout << setw(l1) << "double digits =  2^";
    cout << setw(l1) << to_string(numeric_limits<double>::digits) << endl;
    cout << setw(l1) << "double digits = 10^";
    cout << setw(l1) << to_string(numeric_limits<double>::digits10) << endl;
    cout << endl;

    cout << setw(l1) << "long double digits =  2^";
    cout << setw(l1) << to_string(numeric_limits<long double>::digits) << endl;
    cout << setw(l1) << "long double digits = 10^";
    cout << setw(l1) << to_string(numeric_limits<long double>::digits10) << endl;
    cout << endl;

    return EXIT_SUCCESS;
}
