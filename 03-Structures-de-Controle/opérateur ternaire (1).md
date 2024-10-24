~~~cpp 

if (a > 0) {b += a;} else {b -= 2*a;}
b = a < 0 ? b + a : b - 2*a;

if (d == 0.) {r = 1e100;} else {r = n/d; }
r = d == 0. ? 1e100 : n/d;

if (a > 0) {b += 1;} else if (a == 0) {b = 0;} else {b *= 2;}
b = a > 0 ? b + 1 : (a == 0 ? 0 : b * 2);

~~~


