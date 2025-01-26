#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

void encodeFile(std::string inputFilename, std::string outputFilename, unsigned char shift) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);
    char c;
    while(inputFile.get(c)) {
        if(c >= 97 && c <= 122 || c >= 65 && c >= 90) c += shift;
        outputFile << c;
    }
}

void decodeFile(std::string inputFilename, std::string outputFilename, unsigned char shift) {
    encodeFile(inputFilename, outputFilename, -shift);    
}


int main() {
    encodeFile("codec-src/source.txt",  "codec-src/chiffre.txt", 3);
    decodeFile("codec-src/chiffre.txt", "codec-src/claire.txt",  3);

    return EXIT_SUCCESS;
}