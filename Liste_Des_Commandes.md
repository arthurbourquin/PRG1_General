~~~cpp



/* commentaire */
// commentaire
#include <iostream>
#include "lib.h"
using namespace std;

#ifndef LIB_H
#define LIB_H
//...
#endif



int main() {}



cout << "Hello world" << endl;
cout << "Hello world\n";


int number;
cout << "Enter a number: ";
while (!(cin >> number)) {
    cout << "Try again: ";
    cin.clear(); // Clear error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
}

string line;
cout << "Enter multiple lines (type 'end' to stop):\n";
string lines;
while (true) {
    getline(cin, line);
    if (line == "end") break;
    lines += line + "\n";
}



bool a;
int a; char a;
float a; double a; long a;
short / long / long long, signed / unsigned
3L; 3LL; 3U; 3UL; 3ULL; 3F; 3D; 'c'; "str";
0xff; 07; 0b0101;



std::string s = "Hello"; for (const char& ch : s) {std::cout << ch << " ";}
to_string(a);
string("Hello") + " world";
#include <array>
#include <vector>
std::array<int, 3> a = {1, 2, 3};

vector<int> A(2); → {0, 0};
vector<int> B(4, 1); → {1, 1, 1, 1};
vector<int> C{1, 3, 5, 7, 9};
vector<int> e(C.begin() + 1, C.end() - 1); → {1, 2, 3};
vector<int> f(a.begin(), b.end()); → Error
vector<int> g(a.end(), a.begin()); → Error
vector<int> h(2, v.end()); → Error
vector<int> i(C.begin(), 2); → Error
vector<int> j(C.rbegin(), C.rend()); → {9, 7, 5, 3, 1};

                                                s     v     a
at(i)                                           ✔	✔	✔
front(), back()                                 ✔	✔	✔
size()                                          ✔	✔	✔
begin(), end(), rbegin(), rend()                ✔	✔	✔
insert(p,v), insert(p,n,v), insert(p,it,it)     ✔	✔	
clear()                                         ✔	✔	
pop_back()                                      ✔	✔	
push_back(v)                                    ✔	✔	
erase(.begin(), .end())                         ✔	✔	
resize(s,n)                                     ✔	✔	
capacity()                                            ✔	✔
reserve(v)                                            ✔	
fill(v)                                                     ✔
substr(p,l)                                                 ✔
append()                                                    ✔
find(...), rfind(...)
find_first_of(...), find_last_of(...)
find_first_not_of(...), find_last_not_of(...)
(s/c, p, l)                                                 ✔


int t[n];
int* p = new int [n];
std::span<int> s1(&v[0], v.size());
std::span s2(v);
std::string_view; std::span;

std::tuple<double, string> t = {3.1, "ouais"};
getline(cin, string, ',');



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
cout << setfill('-') << setw(10) << "string" << endl; // ----string
cout << setfill('0') << setw(10) << setprecision(3) << 3 << endl; // 003
cout << fixed << setfill(' ') << setw(10) << setprecision(3) << 17.77777 << endl; // 17.778

struct A {int a; int b; int c;};
A abc = {1, 2, 3};
struct* P = A
(*P).a == P->a == 1

pair<int,int> AB(int a, int b) {return {a + b, a - b};}

#include <iostream>
using namespace std;
enum color {orange, green, brown};
enum class direction {up, down, right, left};
int main() {
    color carot = orange;
    cout << carot << endl;
    direction earth = direction::left;
    cout << static_cast<int>(earth) << endl;
    return 0;
}

template <typename ouais>
void f(ouais a, ouais b) {a + b;}

ouais somme(ouais a, ouais b) {return a + b;}
cout << somme(12, 27)  << endl; // déduction
cout << somme<int>(12, 27)  << endl;
cout << somme<double>(1.3, 4.7)  << endl;

using Vec3 = array<int, 3>;
using Matrice3x3 = array<Vec3, 3>;
template <typename T> bool estInt(T) {return false;}
template<> bool estInt<int>(int) {return true;}
template<> bool estInt<>(int) {return true;}
template<> bool estInt(int) {return true;}

template <int n, typename T> T multiplier(const T& t) {return (T)n * t;}

template <ostream& out> void afficher(const vector<int> &v) {for(int e : v) out << e << ' ';}
int main() {vector<int> v{1,2,3}; afficher<cout>(v); afficher<clog>(v);}

template <typename Fn> void pour_tout(const vector<int> & v, Fn fct) {for(int t : v) fct(t);}

f(T,T)      // -> algo de résolution
f<>(T,T)    // -> algo de résolution sans les types génériques
f<T,T>(T,T) // -> 

// class a vérifier
class Point {
    int x, y, id;
    static int nb;
public:
    Point(int i_x, int i_y) {
        x = i_x;
        y = i_y;
        nb++;
    }
    int getX() const {return x;}
    int getY() const {return y;}
    static int ptNb() {return nb;}
};

#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1, 100);
// use dist(gen); to generate a random value

~~~