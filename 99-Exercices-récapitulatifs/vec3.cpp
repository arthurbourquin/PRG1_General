#include <iostream>
#include <array>
#include <vector>

using namespace std;

class MonException { };

class Vec3 {
   array<double, 3> data;
public:
   Vec3() : data{0,0,0} {}
   template<typename Iterator> Vec3(Iterator first, Iterator last);
   double& operator[](size_t i) { return data[i]; }
   double operator[](size_t i) const { return data[i]; }
   Vec3& operator+=(Vec3 const& other);
   static Vec3 axis(size_t i);
};

template<typename Iterator>
Vec3::Vec3(Iterator first, Iterator last) {
   if (distance(first, last) != 3)
      throw MonException{};
   copy(first, last, data.begin());
}

Vec3 Vec3::axis(size_t i) {
   assert(i < 3);
   Vec3 v{};
   v[i] = 1.;
   return v;
}

Vec3& Vec3::operator+=(Vec3 const& other) {
   for (size_t i = 0; i < 3; ++i)
      data.at(i) += other.data.at(i);
   return *this;
}

Vec3 operator+(Vec3 lhs, Vec3 const& rhs) {
   return lhs += rhs;
}

ostream& operator<<(ostream& o, Vec3 const& v) {
   return o << '(' << v[0] << ',' << v[1] << ',' << v[2] << ')';
}

int main() {
   Vec3 v1{};
   cout << "v1 = " << v1 << endl;

   v1[2] = 2;
   cout << "v1 = " << v1 << endl;

   array a{1., 3., 2.};
   const Vec3 v2(a.begin(),a.end());
   cout << "v2 = " << v2 << endl;

   for (size_t i = 0; i < 3; ++i)
      cout << "v2[" << i << "] = " << v2[i] << ((i < 2) ? ", " : "\n");

   vector b{4., 2., 5.};
   Vec3 v3(b.begin(), b.end());
   cout << "v3 = " << v3 << endl;

   Vec3 v4 = v2 + v3;
   cout << "v4 = " << v4 << endl;

   v4 += v2;
   cout << "v4 = " << v4 << endl;

   Vec3 x = Vec3::axis(0);
   cout << "x = " << x << endl;
   Vec3 y = Vec3::axis(1);
   cout << "y = " << y << endl;
   Vec3 z = Vec3::axis(2);
   cout << "z = " << z << endl;
}

/*
v1 = (0,0,0)
v1 = (0,0,2)
v2 = (1,3,2)
v2[0] = 1, v2[1] = 3, v2[2] = 2
v3 = (4,2,5)
v4 = (5,5,7)
v4 = (6,8,9)
x = (1,0,0)
y = (0,1,0)
z = (0,0,1)
*/