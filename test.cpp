#include <iostream>

using namespace std;

int main() {
{for(int i = 0; i < 10; i++) {std::cout << i;}}
{int i = 0; while(i < 10){std::cout << i;; i++;}}
{int i = 0; while(true){std::cout << i;; i++; if(i > 10) {break;}}}
{int i = 0; do {std::cout << i;; i++;} while(i < 10);}
{int n = 1; switch(n) {case 1:std::cout << "c1";; break; case 2:std::cout << "c2";; break; default:break;}}
{std::string s = "Hello";for (const char& ch : s) {std::cout << ch << " ";}}
//std::vector<int> V = {1, 2, 3, 4, 5}; for (const auto& v : V) {std::cout << v;}
}