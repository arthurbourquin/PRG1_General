#include <iostream>
using namespace std;

double cyldr_vol(double r, double h) {
    return 3.14159265358979323846 * r * r * h; 
}
double trk_cyldr_vol(double rBig, double rSmall, double h) {
    double H = h * rBig / rSmall;
    return cyldr_vol(rBig, H) - cyldr_vol(rSmall, H - h);
}
int main() {
    cout << "Enter dimesions in cm 1. Body height, 2. Bottleneck height, 3. Tip height, 4. Bottle diameter, 5. Tip diameter" << endl;
    double h1, h2, h3, r1, r2;
    cout << "Body height: "; cin >> h1;
    cout << "Bottleneck height: "; cin >> h2;
    cout << "Tip height: "; cin >> h3;
    cout << "Bottle diameter: "; cin >> r1; r1 /= 2;
    cout << "Tip diameter: "; cin >> r2; r2 /= 2;
    double v1 = cyldr_vol(r1, h1);
    double v2 = trk_cyldr_vol(r1, r2, h2);
    double v3 = cyldr_vol(r2, h3);
    double volume = v1 + v2 + v3;
    volume /= 100; // conversion 1 cm3 = 0.01 dl
    cout << "Bottle volume is: " << volume << "dl" << endl;
    return 0;
}