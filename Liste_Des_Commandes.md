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
to_string(value);

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

#include <iostream>       // input / iutput        stream  - <istream> <ostream>
#include <fstream>        // input / output file   stream  - <ifstream> <ofstream>
#include <sstream>        // input / output string stream  - <istringstream> <ostringstream>
#include <string>         // String operations
#include <iomanip>
#include <cmath>          // Math functions
#include <random>         // Random number generation
#include <chrono>         // Date and time utilities
#include <array>          // Fixed-size array
#include <vector>         // Dynamic array
#include <algorithm>      // Algorithms (sort, find, etc.)

rand() % 10;
rand() % (max - min + 1) + min;
dist_int(i, j); dist_float(f, g); dist_real(f, g); dist_normal(f, g); dist_bernoulli(f);

#include <cstdlib>
#include <ctime
srand(static_cast<unsigned int>(time(nullptr)));

std::setw(5); std::setprecision(4); // non persistants
std::setfill(' '); std::setfixed; std::scientific; std::showpos; std::right; std::left; std::internal; std::boolalpha;
cout << setfill(' ') << setw(10) << "Arthur Bourquin" << endl;
cout << setfill(' ') << setw(10) << fixed << setprecision(2) << 3.37423863986539865 << endl;

algorithm, array, atomic, bitset, chrono, complex, condition_variable, cctype, cerrno, cmath, cfloat, climits, csetjmp, csignal, cstdlib, cstring, ctime, deque, exception, filesystem, fstream, functional, future, initializer_list, iomanip, iostream, istream, iterator, limits, list, map, memory, mutex, new, numeric, ostream, queue, random, regex, set, shared_mutex, sstream, stack, stdexcept, string, string_view, thread, tuple, type_traits, unordered_map, unordered_set, utility, variant, vector
~~~~

