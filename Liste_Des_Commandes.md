~~~cpp
/*
commentaire
*/
#include <iostream> // commentaire
#include <cstdlib>
using namespace std;
using Vec3 = array<int, 3>;
using Matrice3x3 = array<Vec3, 3>;

int main() {}

cout << "Hello world" << endl;
cin >> a;

bool a = true;
int a; char a;
float a; double a; long a;
short / long / long long, signed / unsigned

std::string s = "Hello";for (const char& ch : s) {std::cout << ch << " ";}
std::array<int, 3> a = {1, 2, 3};
std::vector<int> v = {1, 2, 3};
std::tuple<bool, int, float, double, char, string> g = {true, 1, 1.5f, 3.1415926535, 'x', "ouais"};
to_string(a); string("Hello") + " world"
#include <vector>
resize(a,b); clear(); pop_back(); push_back(a); insert(); erase();
getline(cin, variable, ',');

std::string_view; std::span;

std::vector<int> v {1, 2, 3, 4};
span<int> s1(&v[0], v.size());
span s2(v);

++i i++
'a' + 1 = 'b'

algorithm, array, atomic, bitset, chrono, complex, condition_variable, cctype, cerrno, cmath, cfloat, climits, csetjmp, csignal, cstdlib, cstring, ctime, deque, exception, filesystem, fstream, functional, future, initializer_list, iomanip, iostream, istream, iterator, limits, list, map, memory, mutex, new, numeric, ostream, queue, random, regex, set, shared_mutex, sstream, stack, stdexcept, string, string_view, thread, tuple, type_traits, unordered_map, unordered_set, utility, variant, vector

int* a = 7
int& b = a
a == 7
&a == 0x7ffee4933868
*p == 7
p == 0x7ffee4933868

::  a++  a--  *a  &a  *  /  %  +  -  <<  >>  <=>  <  <=  >  >=  ==  !=  &&  ||  a?b:c  =  +=  -=  *=  /=  %=  ,

typeid()

a == b ? c : d

for(int i = 0; i < 10; i++) {std::cout << i;}
for(int e : a) cout << e;   
for(int& e : a) e++;
int i = 0; while(i < 10){std::cout << i;; i++;}
int i = 0; while(true){std::cout << i;; i++; if(i > 10) {break;}}
int i = 0; do {std::cout << i;; i++;} while(i < 10);
int n = 1; switch(n) {case 1:std::cout << "c1";; break; case 2:std::cout << "c2";; break; default:break;}
0x10ull;

#include <iostream>
#include <fstream> // file
#include <sstream> // string
#include <string> 
#include <iomanip>
#include <cmath> 
#include <random>
#include <array>
#include <vector>
#include <span>

rand() % 10;
rand() % (max - min + 1) + min;

#include <cstdlib>
#include <ctime
srand(static_cast<unsigned int>(time(nullptr)));

std::setw(5); std::setprecision(4); // non persistants
std::setfill(' '); std::setfixed; std::scientific; std::showpos; std::right; std::left; std::internal; std::boolalpha;
cout << setfill(' ') << setw(10) << "Arthur Bourquin" << endl;
cout << setfill(' ') << setw(10) << fixed << setprecision(2) << 3.37423863986539865 << endl;

struct A {int a; int b; int c;};
A abc = {1, 2, 3};
struct* P = A
(*P).a == P->a == 1

pair<int,int> AB(int a, int b) {return {a + b, a - b};}

enum Jour {FAUX, LU, MA, ME, JE, VE, SA, DI}; Jour cool = SA; // SA == 1

~~~~

