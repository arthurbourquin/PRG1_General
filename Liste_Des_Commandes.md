~~~cpp
/*
commentaire
*/
#include <iostream> // commentaire
#include <cstdlib>
using namespace std;

int main() {}

cout << "Hello world" << endl;
cin >> a;

bool a = true;
int a; char a;
float a; double a; long a;
short / long / long long, signed / unsigned

std::string a = "Hello";
std::array<double, 4> g = {1.0, 1.5, 3.1415926535, 2.0}; std::array a { 1, 2, 3};
std::vector<int> h = {1, 2, 3, 4};
std::tuple<bool, int, float, double, char, string> g = {true, 1, 1.5f, 3.1415926535, 'x', "ouais"};

++i i++
'a' + 1 = 'b'
string("Hello") + " world"

a return 7
&a return 0x7ffee4933868
*p return 7
p return 0x7ffee4933868

::  a++  a--  *a  &a  *  /  %  +  -  <<  >>  <=>  <  <=  >  >=  ==  !=  &&  ||  a?b:c  =  +=  -=  *=  /=  %=  ,

a == b ? c : d

for(int i = 0; i < 10; i++) {std::cout << i;}
int i = 0; while(i < 10){std::cout << i;; i++;}
int i = 0; while(true){std::cout << i;; i++; if(i > 10) {break;}}
int i = 0; do {std::cout << i;; i++;} while(i < 10);
int n = 1; switch(n) {case 1:std::cout << "c1";; break; case 2:std::cout << "c2";; break; default:break;}
std::string s = "Hello";for (const char& ch : s) {std::cout << ch << " ";}
std::vector<int> V = {1, 2, 3, 4, 5}; for (const auto& v : V) {std::cout << v;} // X

~~~