#include <iostream>
#include <iomanip>
#include <cmath>

void print(double a) {
    std::cout << std::hexfloat << a << std::endl;
}

int main() {
    std::cout << std::endl;
    for(int a = 1; a < 8; a++){
        print(a * a);
    }
    std::cout << std::endl;
    for(int a = 1; a < 8; a++){
        print(pow(10, a));
    }
    std::cout << std::endl;
    
    return 0;
}