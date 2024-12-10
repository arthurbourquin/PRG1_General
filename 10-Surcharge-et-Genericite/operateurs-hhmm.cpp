// WIP

#include <iostream>
#include <limits>
using namespace std;

struct HeureMinute {
   int heure;
   int minute;
};

istream& operator>> (istream& is, HeureMinute& hm) {
   is >> hm.heure >> hm.minute;
   return is;
};

ostream& operator<< (ostream& is, const HeureMinute& hm) {
   return is << hm.heure << ":" << hm.minute;
}

bool operator< (const HeureMinute& lhs, const HeureMinute& rhs) {
   if(lhs.heure != rhs.heure) {
      return lhs.heure < rhs.heure;
   } else {
      return lhs.minute < rhs.minute;
   }
}
bool operator>  (const HeureMinute& lhs, const HeureMinute& rhs) {return rhs < lhs;}
bool operator<= (const HeureMinute& lhs, const HeureMinute& rhs) {return !(lhs > rhs);}
bool operator>= (const HeureMinute& lhs, const HeureMinute& rhs) {return !(lhs < rhs);}
bool operator== (const HeureMinute& lhs, const HeureMinute& rhs) {return (lhs.heure != rhs.heure) && (lhs.minute != rhs.minute);}
bool operator!= (const HeureMinute& lhs, const HeureMinute& rhs) {return !(lhs == rhs);}

HeureMinute operator+ (const HeureMinute& lhs, const HeureMinute& rhs) {
   HeureMinute hm;
   hm.heure = lhs.heure + rhs.heure + (lhs.minute + rhs.minute) / 60;
   hm.minute = (lhs.minute + rhs.minute) % 60;
   return hm;
}
HeureMinute operator+ (const HeureMinute& lhs, int rhs) {
   return lhs + HeureMinute{0, rhs};
}
HeureMinute operator+ (int lhs, const HeureMinute& rhs) {return rhs + lhs;}

HeureMinute& operator+= (HeureMinute& lhs, const HeureMinute& rhs) {
   lhs = lhs + rhs;
   return lhs;
}
HeureMinute& operator+= (HeureMinute& lhs, int rhs) {
   return lhs += HeureMinute{0, rhs};
}
HeureMinute& operator+= (int lhs, HeureMinute& rhs) {return rhs += lhs;}

HeureMinute& operator++ (HeureMinute& lhs) {
   return lhs += 1;
}
HeureMinute& operator++ (HeureMinute& lhs, int) {
   HeureMinute temp = lhs;
   lhs + 1;
   return lhs;
}

HeureMinute saisie(const string& msg) {
   HeureMinute hm;
   bool erreur;
   do {
      cout << msg;
      cin >> hm;
      erreur = cin.fail();
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (erreur);
   return hm;
}


int main() {

HeureMinute hm1 = {12, 34};
HeureMinute hm2 = {21, 43};

cout << boolalpha;
cout << hm1 << " <  " << hm2 << "  : " << (hm1 <  hm2) << endl;
cout << hm1 << " >  " << hm2 << "  : " << (hm1 >  hm2) << endl;
cout << hm1 << " <= " << hm2 << "  : " << (hm1 <= hm2) << endl;
cout << hm1 << " >= " << hm2 << "  : " << (hm1 >= hm2) << endl;
cout << hm1 << " == " << hm2 << "  : " << (hm1 == hm2) << endl;
cout << hm1 << " != " << hm2 << "  : " << (hm1 != hm2) << endl;
cout << hm1 << " +  " << hm2 << "  : " << (hm1 +  hm2) << endl;
cout << hm1 << " +  " << 44  << "     : " << (hm1 +  44 ) << endl;
cout << 44  << "    +  " << hm1 << "  : " << (44  +  hm1) << endl;
cout << hm1 << " += "  << 2 << "      : " << (hm1+=2 )    << endl;

cout << "++" << hm1  << "\t\t: " << ++hm1 << endl;
cout << hm1  << "++" << "\t\t: " << hm1++ << endl;
cout << hm1 << endl;

cout << endl;
HeureMinute hm3 = saisie("heure [hh:mm]: ");
cout << "votre saisie : " << hm3 << endl;

   return EXIT_SUCCESS;
}

/*
12:34 <  21:43  : true
12:34 >  21:43  : false
12:34 <= 21:43  : true
12:34 >= 21:43  : false
12:34 == 21:43  : false
12:34 != 21:43  : true
12:34 +  21:43  : 34:17
12:34 +  44     : 13:18
44    +  12:34  : 13:18
12:34 += 2      : 12:36
++12:36         : 12:37
12:37++         : 12:37
12:38

heure [hh:mm]: 12 34
heure [hh:mm]: 12:34
votre saisie : 12:34
*/