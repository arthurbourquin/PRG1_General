#include <iostream>
#include <cmath>
using namespace std;

struct DMS {
   float deg;
   float min;
   long double sec;
};

struct Coord_DMS {
   DMS lon;
   DMS lat;
};

struct Coord_DD {
   long double lon;
   long double lat;
};

void print_DMS(Coord_DMS c) {
   cout << "Latitude  : N " << c.lon.deg << "°" << c.lon.min << "'" << c.lon.sec << "''" << endl;
   cout << "Longitude : E " << c.lat.deg << "°" << c.lat.min << "'" << c.lat.sec << "''" << endl;
}

void print_DD(Coord_DD c) {
   cout << c.lon << endl;
   cout << c.lat << endl;
}

Coord_DMS DD_to_DMS(Coord_DD input) {
   Coord_DMS output;
   output.lon.deg = D_to_DMS(input.lon).deg;
   output.lon.min = D_to_DMS(input.lon).min;
   output.lon.sec = D_to_DMS(input.lon).sec;
   return output;
}

DMS D_to_DMS(double input) {
   DMS result;
   result.deg = floor(input);
   result.min = floor((input - result.deg) * 60);
   result.sec = (input - result.deg - (result.min / 60)) * 3600;
   return result;
}

Coord_DD DMS_to_DD(Coord_DMS input) {
   Coord_DD output;
   output.lon = input.lon.deg + input.lon.min / 60 + input.lon.sec / 3600;
   output.lat = input.lat.deg + input.lat.min / 60 + input.lat.sec / 3600;
   return output;
}

int main() {
//   Coord_DMS Yverdon_DMS = {Dir_NS::N, 46, 46, 42.856, Dir_EW::E, 6, 38, 27.296};
   Coord_DMS Yverdon_DMS = {46, 46, 42.856, 6, 38, 27.296};

   Coord_DD Yverdon_DD = {46.7785711, 6.6409158};

   print_DMS(Yverdon_DMS);
   cout << endl;

   print_DD (Yverdon_DD);
   cout << endl;

   print_DMS(DD_to_DMS(Yverdon_DD));
   cout << endl;

   print_DD(DMS_to_DD(Yverdon_DMS));
   cout << endl;

   return EXIT_SUCCESS;
}

/*
Latitude  : N 46°46'42.856"
Longitude : E 6°38'27.296"

Latitude  : 46.778571
Longitude : 6.640916

Latitude  : N 46°46'42.856"
Longitude : E 6°38'27.297"

Latitude  : 46.778571
Longitude : 6.640916
*/