#include <iostream>
#include <iomanip>
using namespace std;

template<typename T, typename T2 = T>
class Frac {
private:
    T num; 
    T den; 
    bool undefined;
public:
    Frac(T init_num, T init_den) : num(init_num), den(init_den), undefined(false) {if(den == 0) {num = 0; den = 0; undefined = true;}}
    ~Frac() {}

    double  get_num()               const   {return num;}
    void    set_num(double inum)            {num = inum;}
    double  get_den()               const   {return den;}
    void    set_den(double iden)            {den = iden;}

    void update() {
        if (den == 0) {num = 0; den = 0; undefined = true; return;}
        simplify();
        if (den < 0) {num = -num; den = -den;}
    }

    void simplify() {
        T a = num;
        T b = den;
        while (b != 0) {
            int reste = a % b;
            a = b;
            b = reste;
        }
        num /= a;
        den /= a;
    }

    Frac & invert() {
        T tmp = num;
        num = den;
        den = tmp;
        return (*this);
    }

    Frac & operator = (const Frac & other) {num = other.num; den = other.den; return (*this);}
    Frac & operator = (const T2 & other) {num = other; den = 1; return (*this);}
    bool operator == (Frac other) {simplify(); other.simplify(); return (num == other.num && den == other.den);}
    bool operator == (short other) {return (T2)num / (T2)den == other;}

    Frac & operator +=  (const Frac & other)        {num = (num * other.den + other.num * den); den = (den * other.den); update(); return (*this);}
    Frac & operator -=  (const Frac & other)        {(*this) += (- 1) * other; update(); return (*this);}
    Frac & operator *=  (const Frac & other)        {num *= other.num; den *= other.den; update(); return (*this);}
    Frac & operator /=  (const Frac & other)        {(*this) *= Frac(other.den, other.num); update(); return (*this);}
    Frac operator +     (const Frac & other) const  {Frac result = (*this); result += other; result.update(); return result;}
    Frac operator -     (const Frac & other) const  {Frac result = (*this); result -= other; result.update(); return result;}
    Frac operator *     (const Frac & other) const  {Frac result = (*this); result *= other; result.update(); return result;}
    Frac operator /     (const Frac & other) const  {Frac result = (*this); result /= other; result.update(); return result;}

    Frac & operator +=  (long long other)       {num += other * den; update(); return (*this);}
    Frac & operator -=  (long long other)       {num -= other * den; update(); return (*this);}
    Frac & operator *=  (long long other)       {num *= other; update(); return (*this);}
    Frac & operator /=  (long long other)       {if(other == 0) {num = 1; den = 1; undefined = true; }
                                                 else           {den *= other; update();}
                                                 return (*this);}
    Frac operator *     (long long other) const {Frac result = (*this); result *= other; result.update(); return result;}
    Frac operator -     (long long other) const {Frac result = (*this); result -= other; result.update(); return result;}
    Frac operator +     (long long other) const {Frac result = (*this); result += other; result.update(); return result;}
    Frac operator /     (long long other) const {Frac result = (*this); result /= other; result.update(); return result;}

    friend T2 & operator +=   (T2 & lhs, const Frac & rhs)        {lhs = lhs + (long double)rhs.num / (long double)rhs.den; return lhs;}
    friend T2 operator +      (const T2 & lhs, const Frac & rhs)  {T2 result = lhs; result += rhs; return result;}
    friend T2 & operator *=   (T2 & lhs, const Frac & rhs)        {lhs = lhs * (long double)rhs.num / (long double)rhs.den; return lhs;}
    friend T2 operator *      (const T2 & lhs, const Frac & rhs)  {T2 result = lhs; result *= rhs; return result;}
    friend T2 & operator -=   (T2 & lhs, const Frac & rhs)        {lhs = lhs - (long double)rhs.num / (long double)rhs.den; return lhs;}
    friend T2 operator -      (const T2 & lhs, const Frac & rhs)  {T2 result = lhs; result -= rhs; return result;}
    friend T2 & operator /=   (T2 & lhs, const Frac & rhs)        {lhs = lhs * (long double)rhs.den / (long double)rhs.num; return lhs;}
    friend T2 operator /      (const T2 & lhs, const Frac & rhs)  {T2 result = lhs; result /= rhs; return result;}

    friend ostream & operator << (ostream & os, const Frac & f) {
        if(f.undefined) {
            os << "infinite or undefined";
        } else if(f.den == 1){
            os << f.num;
        } else {
            os << f.num << "/" << f.den;
        }
        return os; 
    }
};


int main() {

    /* BEGIN DEMO FRAC */

    int w = 40;
    
    cout << setw(w) << endl;
    cout << setw(w) << setfill(' ');

    cout << setw(w) << "Frac(13, 2)" << "    " << Frac(13, 2) << endl;
    cout << setw(w) << "0.0 + Frac(13, 2)" << "    " << 0.0 + Frac(13, 2) << endl;
    cout << setw(w) << "Frac(13, 0)" << "    " << Frac(13, 0) << endl;
    cout << setw(w) << endl;

    cout << setw(w) << "Frac(13, 7) + Frac(12, 9)" << "    " << Frac(13, 7) + Frac(12, 9) << endl;
    cout << setw(w) << "Frac(13, 7) - Frac(12, 9)" << "    " << Frac(13, 7) - Frac(12, 9) << endl;
    cout << setw(w) << "Frac(13, 7) * Frac(12, 9)" << "    " << Frac(13, 7) * Frac(12, 9) << endl;
    cout << setw(w) << "Frac(13, 7) / Frac(12, 9)" << "    " << Frac(13, 7) / Frac(12, 9) << endl;
    cout << setw(w) << endl;

    cout << setw(w) << "Frac(13, 7) + 2.0" << "    " << Frac(13, 7) + 2.0 << endl;
    cout << setw(w) << "Frac(13, 7) - 2.0" << "    " << Frac(13, 7) - 2.0 << endl;
    cout << setw(w) << "Frac(13, 7) * 2.0" << "    " << Frac(13, 7) * 2.0 << endl;
    cout << setw(w) << "Frac(13, 7) / 2.0" << "    " << Frac(13, 7) / 2.0 << endl;
    cout << setw(w) << endl;

    cout << setw(w) << "2.0 + Frac(13, 7)" << "    " << 2.0 + Frac(13, 7) << endl;
    cout << setw(w) << "2.0 - Frac(13, 7)" << "    " << 2.0 - Frac(13, 7) << endl;
    cout << setw(w) << "2.0 * Frac(13, 7)" << "    " << 2.0 * Frac(13, 7) << endl;
    cout << setw(w) << "2.0 / Frac(13, 7)" << "    " << 2.0 / Frac(13, 7) << endl;
    cout << setw(w) << endl;

    Frac b(16777216, 4194304);
    cout << setw(w) << "Frac b(16777216, 4194304)" << "    " << b << endl;
    b.simplify();
    cout << setw(w) << "b.simplify();" << "    " << b << endl;
    cout << setw(w) << setw(w) << endl;

    Frac c(5, 7);
    cout << setw(w) << "Frac c(5, 7); c" << "    " << c << endl;
    c.invert();
    cout << setw(w) << "c.invert()" << "    " << c << endl;
    c.invert();
    cout << setw(w) << "c.invert()" << "    " << c << endl;
    cout << setw(w) << "1.0 / c" << "    " << 1.0 / c << endl;
    cout << setw(w) << endl;

    cout << setw(w) << "Frac(1, 1) / Frac(13, 9)" << "    " << Frac(1, 1) / Frac(13, 9) << endl;
    cout << setw(w) << endl;

    /* END DEMO FRAC */

    return 0;
}
