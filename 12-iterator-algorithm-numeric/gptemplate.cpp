// GPT

#include <iostream>
#include <string>

// Template avec trois types génériques
template<typename A, typename B, typename C>
C combine(A a, B b) {
    if constexpr (std::is_same<C, std::string>::value) {
        return std::to_string(a) + std::to_string(b); // Conversion explicite pour std::string
    } else {
        return static_cast<C>(a) + static_cast<C>(b); // Combinaison normale pour les autres types
    }
}

int main() {
    // Exemple avec différents types
    std::cout << "Combine int et double en float : " 
              << combine<int, double, float>(5, 3.7) << std::endl;

    std::cout << "Combine char et int en std::string : " 
              << combine<char, int, std::string>('A', 10) << std::endl;

    return 0;
}