# Général
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
~~~

# Librairies
~~~cpp
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
~~~


# cin
~~~cpp
int number;
cout << "Enter a number: ";
while (!(cin >> number)) { // il utilise cin.good()
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

getline(cin, line, ',');

cout << "des mots séparés par des espaces svp : " << endl;
string a;
string b;
string c;
string d;
// ouais cheval salut pourquoi d'accord
cin >> a;
cin >> b;
cin >> c;
cin >> d;
cout << "premier mot :   " << a << endl; // premier mot :   ouais
cout << "deuxième mot :  " << b << endl; // deuxième mot :  cheval
cout << "troisième mot : " << c << endl; // troisième mot : salut
cout << "quatrième mot : " << d << endl; // quatrième mot : pourquoi
~~~


# Types de base
~~~cpp
bool a;
int a; char a;
float a; double a; long a;
short / long / long long, signed / unsigned
3L; 3LL; 3U; 3UL; 3ULL; 3F; 3D; 'c'; "str"s;
0xff; 07; 0b0101;
~~~


# Listes

## Strings
~~~cpp
cout << "Hello caca prout merde" << endl;
cout << "Hello"s + " caca"s + " prout"s + " merde"s << endl;
string s = "Hello";
cout << string("Hello") + " caca" + " prout" + " merde" << endl;
string s2 = string("Hello") + " caca" + " prout" + " merde";
cout << s2 << endl;
string s3 = s +  " caca" + " prout" + " merde";
cout << s3 << endl;
for(const char & c : s) {cout << c << " ";} cout << endl;
for(int i = 0; i < s.size(); ++i) {cout << s.at(i) << " ";} cout << endl;
for(int i = 0; i < s.size(); ++i) {cout << s.at(s.size() - 1 - i) << " ";} cout << endl;
for(auto it = s.begin(); it != s.end(); ++it) {cout << * it << " ";} cout << endl;
for(auto it = s.rbegin(); it != s.rend(); ++it) {cout << * it << " ";} cout << endl;
to_string(num);
cout << 'a' + 1 << endl; // 98
cout << 'a' + (char)1 << endl; // 98
cout << (char)('a' + 1) << endl; // b
~~~

## Array, Vector
~~~cpp
#include <array>
#include <vector>
array a {1, 2, 3};
array<int, 3> a = {1, 2, 3};
vector<int> A(2); // {0, 0}
vector<int> B(4, 1); // {1, 1, 1, 1}
vector<int> C{1, 3, 5, 7, 9};
vector<int> e(C.begin() + 1, C.end() - 1); // {1, 2, 3}
vector<int> j(C.rbegin(), C.rend()); // {9, 7, 5, 3, 1}
vector<vector<int>> matrix(4, vector<int>(3, 0));
~~~

## span
~~~cpp
int t[n];
int* p = new int [n];
span<int> s1(&v[0], v.size());
span s2(v);
string_view; span;
~~~



# Noms réservés
~~~cpp
algorithm, array, atomic, bitset, chrono, complex, condition_variable, cctype, cerrno, cmath, cfloat, climits, csetjmp, csignal, cstdlib, cstring, ctime, deque, exception, filesystem, fstream, functional, future, initializer_list, iomanip, iostream, istream, iterator, limits, list, map, memory, mutex, new, numeric, ostream, queue, random, regex, set, shared_mutex, sstream, stack, stdexcept, string, string_view, thread, tuple, type_traits, unordered_map, unordered_set, utility, variant, vector
~~~


# Pointeurs
~~~cpp
int a = 7;            // variable
int & ref = a;        // alias
int * ptr = & a;      // pointeur
cout << a << endl;    // 7
cout << ref << endl;  // 7
cout << ptr << endl;  // 0x7ffeeb7f4858
const int * const p1;   // pointeur constant non modifiant
const int *       p2;   // pointeur constant modifiant
      int * const p3;   // pointeur non modifiant
      int *       p4;   // pointeur modifiant
~~~


# Opérateurs
~~~cpp
::   a++   a--   * a   & a   *   /   %   +   -   <<   >>   <=>   <   <=   >   >=   ==   !=   &&   ||   a ? b : c   =   +=   -=   *=   /=   %=   ,
~~~

# Types
~~~cpp
typeid().name()
                      int i
                    float f
                   double d
                   string NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
                     char c
                   size_t m
                 long int l
            long long int x
              long double e
                 unsigned j
           unsigned short t
             unsigned int j
            unsigned long m
       unsigned long long y
                    short s
                short int s
       unsigned short int t
              vector<int> NSt3__16vectorIiNS_9allocatorIiEEEE
            array<int, 5> NSt3__15arrayIiLm5EEE
~~~

# opérateur ternaire
~~~cpp
a == b ? c : d
~~~


# boucles
~~~cpp
for(int i = 0; i < 10; i++) {std::cout << i;}
for(int e : a) cout << e;   
for(int& e : a) e++;
int i = 0; while(i < 10){std::cout << i;; i++;}
int i = 0; while(true){std::cout << i;; i++; if(i > 10) {break;}}
int i = 0; do {std::cout << i;; i++;} while(i < 10);
int n = 1; switch(n) {case 1:std::cout << "c1";; break; case 2:std::cout << "c2";; break; default:break;}
~~~

# Random
~~~cpp
rand() % 10;
rand() % (max - min + 1) + min;

#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1, 100);
// use dist(gen); to generate a random value
~~~

# Formattage cout iomanip
~~~cpp
#include <iomanip>
setw(5); setprecision(4); // non persistants
setfill(' '); setfixed; scientific; showpos; right; left; internal; boolalpha;  
cout << setfill('-') << setw(10) << "string" << endl; // ----string
cout << setfill('0') << setw(10) << setprecision(3) << 3 << endl; // 003
cout << fixed << setfill(' ') << setw(10) << setprecision(3) << 17.77777 << endl; // 17.778
~~~


# Class, Struct, Enum
~~~cpp
class Point {
    int x, y;
    static int nb;
public:
    Point(int init_x, int init_y) : x(init_x), y(init_y) { nb++; }
    Point() : x(0), y(0) { nb++; }
    Point(const Point& p) : x(p.x), y(p.y) { nb++; }
    Point& operator=(const Point& other) {
        if (this == &other) return *this;
        x = other.x;
        y = other.y;
        return *this;
    }
    ~Point() { nb--; }
    int getX() const { return x; }
    int getY() const { return y; }
    static int ptNb() { return nb; }
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};
int Point::nb = 0;
ostream& operator<<(ostream& os, const Point& p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;
}


struct A {int a; int b; int c;};
A abc = {1, 2, 3};
struct* P = A
(*P).a == P->a == 1


pair<int,int> AB(int a, int b) {return {a + b, a - b};}


enum Ouais {ah, ok, pourquoi, cheval};
enum class Ok {non, chocolat, poivre};
cout << ok << endl; // 1
cout << (int)Ok::poivre << endl; // 2
~~~


# Template, généricité
~~~cpp
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

template <ostream & out> void afficher(const vector<int> & v) {for(int e : v) out << e << ' ';}
int main() {vector<int> v{1,2,3}; afficher<cout>(v); afficher<clog>(v);}

template <typename Fn> void pour_tout(const vector<int> & v, Fn fct) {for(int t : v) fct(t);}

f(T,T)      // -> algo de résolution
f<>(T,T)    // -> algo de résolution sans les types génériques
f<T,T>(T,T) // -> 
~~~


# File Stream
~~~cpp
ofstream file("output.txt");
file << "Hello, file!" << endl;
file.close();

ifstream file("output.txt");
string line;
while (getline(file, line)) {
    cout << line << endl;
}
file.close();
~~~


# Surcharge, Overload

**critère 1** appel sans conversion
**critère 2** conversion simple
- ptr à const_ptr
- ref à const_ref
- t[] à ptr
- ptr à t[]
**critère 3** promotion
- bool / char / uchar / short / ushort à int
- float à double
**critère 4** conversion de type

# new delete
~~~cpp
::operator new T; // alloue la mémoire pour un objet T
new(T); // construit un objet T
new T; // les deux précédents dans l'ordre

void * ptr = ::operator new(sizeof(T));  // Allocation de mémoire brute pour un objet de type T
new(ptr) T;  // Construction d'un objet T à l'adresse ptr
T * obj = new T;  // Allocation de mémoire et construction d'un objet de type T

::operator delete(ptr);  // Libération de la mémoire brute
delete obj;  // Déstruction de l'objet et libération de la mémoire allouée
~~~
Pour une bonne pratique, il faut toujours utiliser new et delete dans les classes qu'on crée