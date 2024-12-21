#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

int type_name_w = 25;
int text_maxi_w = 18;
int type_maxi_w = 30;
int text_expo_w = 20;
int type_expo_w = 3;

string integer_to_formatted_string(size_t x) {
    string base = to_string(x);
    string tmp = "";
    int ii = base.length() - 1;
    for(int i = 0; i < base.length(); i++) {
        tmp.push_back(base[ii]);
        ii--;
        if(i % 3 == 2 && ii >= 0) tmp.push_back('\'');
    }
    string revert_back(tmp.rbegin(), tmp.rend());
    return revert_back;
 }

void print_separation_line() {
    string line(100, ' ');
    cout << line << endl;
}

template <typename T>
void f_int(const string& type_name) {
    print_separation_line();
    cout << left;
    cout << setw(type_name_w) << right << type_name << " ";
    cout << setw(text_maxi_w) << left << " max val: ";
    cout << setw(type_maxi_w) << right << integer_to_formatted_string(numeric_limits<T>::max());
    cout << "  =  2^(";
    cout << static_cast<int>(round(log2(numeric_limits<T>::max()))) << ")";
    if (type_name.find("unsigned") == std::string::npos) {
        cout << "- 1";
    }
    cout << endl;
}

template <typename T>
void f_real(const string& type_name) {
    print_separation_line();
    cout << setw(type_name_w) << right << type_name << " ";
    cout << setw(text_maxi_w) << left << " can handle max: ";
    if(type_name == "long double") {
        cout << setw(type_maxi_w) << right << "(too big...)";
    } else {
        cout << setw(type_maxi_w) << right << integer_to_formatted_string(static_cast<size_t>(round(pow(2, numeric_limits<T>::digits))));
    }
    cout << "  =  2^(";
    cout << numeric_limits<T>::digits << ")";
    cout << endl;
}

int main() {

    cout << endl;

    f_int<bool>("bool");
    f_int<char>("char");
    f_int<unsigned char>("unsigned char");
    f_int<short>("short");
    f_int<unsigned short>("unsigned short");
    f_int<int>("int");
    f_int<unsigned int>(" unsignedint");
    f_int<long int>("long int");
    f_int<unsigned long int>("unsigned long int");
    f_int<long long int>("long long int");
    f_int<unsigned long long int>("unsigned long long int");

    f_real<float>("float");
    f_real<double>("double");
    f_real<long double>("long double");

    print_separation_line();

    cout << endl;

    return 0;
}
