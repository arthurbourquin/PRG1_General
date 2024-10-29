#include <iostream>
#include <iomanip>
using namespace std;

int main() {
using testedType = int; // ancien / autre : 'typedef int testedType;'
cout << setfill(' ');
cout << "taille en byte : " << setw(12) << right << sizeof(testedType) << " bytes" << endl;
cout << "taille en      : " << setw(12) << right << numeric_limits<testedType>::digits << " bits" << endl;
cout << "intervalle       " << endl;
cout << "de             : " << setw(12) << right << numeric_limits<testedType>::lowest() << endl;
cout << "à              : " << setw(12) << right << numeric_limits<testedType>::max() << endl;
cout << "signé          : " << setw(12) << right << (numeric_limits<testedType>::is_signed == true ? "True" : "False") << endl;
return 1;
}