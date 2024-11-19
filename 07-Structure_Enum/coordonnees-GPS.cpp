/*
Popurquoi je dois utiliser -std=c++11 ?
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Coord_real {long double lon; long double lat;};
struct DMS {int deg; int min; long double sec;};
struct Coord_DMS {DMS lon; DMS lat;};
string label(char dir) {if(dir == 'N') {return "Latitude  : N ";} else {return "Longitude : E ";}}

void print_DMS(Coord_DMS c) {
   cout << label('N') << c.lon.deg << "°" << c.lon.min << "'" << c.lon.sec << "''" << endl;
   cout << label('E') << c.lat.deg << "°" << c.lat.min << "'" << c.lat.sec << "''" << endl;
}

void print_real(Coord_real c) {
   cout << label('N') << c.lon << endl;
   cout << label('E') << c.lat << endl;
}

DMS real_to_HMS(long double input) {
   int deg = floor(input);
   int min = floor((input - deg) * 60.0);
   long double sec = (input - deg - (min / 60)) * 3600.0;
   return {deg, min, sec};
}

long double DMS_to_real(DMS input) {
   return input.deg + input.min / 60.0 + input.sec / 3600.0;
}

Coord_real DMS_to_real(Coord_DMS input) {
   return {DMS_to_real(input.lon), DMS_to_real(input.lat)};
}
Coord_DMS real_to_DMS(Coord_real input) {
   return {real_to_HMS(input.lon), real_to_HMS(input.lat)};
}

int main() {

   cout << endl;

   Coord_DMS Yverdon_DMS = {46, 46, 42.856, 6, 38, 27.296};

   Coord_real Yverdon_real = {46.7785711, 6.6409158};

   print_DMS(Yverdon_DMS);
   cout << endl;

   print_real (Yverdon_real);
   cout << endl;

   print_DMS(real_to_DMS(Yverdon_real));
   cout << endl;

   print_real(DMS_to_real(Yverdon_DMS));
   cout << endl;

   return EXIT_SUCCESS;
}