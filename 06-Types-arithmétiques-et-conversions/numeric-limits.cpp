#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

void format() {
    cout << setw(4) << right; // Right align next output
}

void bitSize(int a) {
    string s = (a > 1) ? "s" : "";
    
    // Calculate 2^a using an unsigned long long to prevent overflow
    unsigned long long value = static_cast<unsigned long long>(pow(2, a));
    
    cout << setw(16) << right << value << " possibilité" << s; // Align bits
}

int main() {
    cout << endl;
    cout << "Spécifications de float :" << endl;
    cout << endl;
    int total = sizeof(float) * CHAR_BIT; // Total bits
    int base = numeric_limits<float>::radix; // Base
    int s = (int) numeric_limits<float>::is_signed; // Sign
    int p = numeric_limits<float>::digits; // Precision

    cout << setfill(' ');
    cout << "Base      : "; format(); cout << base; bitSize(base); cout << endl;
    cout << "Bits      : "; format(); cout << total; bitSize(total); cout << endl;
    cout << "Signe     : "; format(); cout << s; bitSize(s); cout << endl;
    cout << "Mantisse  : "; format(); cout << p - 1; bitSize(p - 1); cout << endl;
    cout << "Exposant  : "; format(); cout << total - (p - 1) - s; bitSize(total - (p - 1) - s); cout << endl;
    cout << "Précision : "; format(); cout << p; bitSize(p); cout << endl;

    cout << endl;
    cout << "test " << endl;
    int number = 87124569;
    int magnitude = log10(number);
    for(int i = 0; i < magnitude + 1; i++) {
        cout << (number % static_cast<int>(pow(10, i + 1)) - number % static_cast<int>(pow(10, i))) / magnitude << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}