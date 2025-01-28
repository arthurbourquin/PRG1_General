#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
class Frac {
private:
    T num; 
    T den; 
    bool undefined;
public:
    static bool show_denum_if_one;
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
        long long div = 2;
        while(div < 10e5) {
            if(num % div == 0 && den % div == 0) {
                num /= div; den /= div;
            } else {
                div++;
            }
        }
    }

    Frac & invert() {
        T tmp = num;
        num = den;
        den = tmp;
        return (*this);
    }

    Frac & operator +=  (const Frac & other)        {num = (num * other.den + other.num * den); den = (den * other.den); update(); return (*this);}
    Frac operator +     (const Frac & other) const  {Frac result = (*this); result += other; result.update(); return result;}
    Frac & operator -=  (const Frac & other)        {(*this) += (- 1) * other; update(); return (*this);}
    Frac operator -     (const Frac & other) const  {Frac result = (*this); result -= other; result.update(); return result;}
    Frac & operator *=  (const Frac & other)        {num *= other.num; den *= other.den; update(); return (*this);}
    Frac operator *     (const Frac & other) const  {Frac result = (*this); result *= other; result.update(); return result;}
    Frac & operator /=  (const Frac & other)        {(*this) *= Frac(other.den, other.num); update(); return (*this);}
    Frac operator /     (const Frac & other) const  {Frac result = (*this); result /= other; result.update(); return result;}

    Frac & operator +=  (long long other)       {num += other * den; update(); return (*this);}
    Frac operator +     (long long other) const {Frac result = (*this); result += other; result.update(); return result;}
    Frac & operator -=  (long long other)       {num -= other * den; update(); return (*this);}
    Frac operator -     (long long other) const {Frac result = (*this); result -= other; result.update(); return result;}
    Frac & operator *=  (long long other)       {num *= other; update(); return (*this);}
    Frac operator *     (long long other) const {Frac result = (*this); result *= other; result.update(); return result;}
    Frac & operator /=  (long long other)       {if(other == 0) {num = 1; den = 1; undefined = true; } else
                                                                {den *= other; update();}
                                                                return (*this);}
    Frac operator /     (long long other) const {Frac result = (*this); result /= other; result.update(); return result;}

    template<typename T2> friend T2 & operator +=   (T2 & lhs, const Frac & rhs)        {lhs = lhs + rhs.num / rhs.den; return lhs;}
    template<typename T2> friend T2 operator +      (const T2 & lhs, const Frac & rhs)  {T2 result = lhs; result += rhs; return result;}
    template<typename T2> friend T2 & operator *=   (T2 & lhs, const Frac & rhs)        {lhs = lhs * rhs.num / rhs.den; return lhs;}
    template<typename T2> friend T2 operator *      (const T2 & lhs, const Frac & rhs)  {T2 result = lhs; result *= rhs; return result;}
    template<typename T2> friend T2 & operator -=   (T2 & lhs, const Frac & rhs)        {lhs = lhs - rhs.num / rhs.den; return lhs;}
    template<typename T2> friend T2 operator -      (const T2 & lhs, const Frac & rhs)  {T2 result = lhs; result -= rhs; return result;}
    template<typename T2> friend T2 & operator /=   (T2 & lhs, const Frac & rhs)        {lhs = lhs * rhs.den / rhs.num; return lhs;}
    template<typename T2> friend T2 operator /      (const T2 & lhs, const Frac & rhs)  {T2 result = lhs; result /= rhs; return result;}

    friend ostream & operator << (ostream & os, const Frac & f) {
        if(f.undefined) {
            os << "infinite or undefined";
        } else if(show_denum_if_one && f.den == 1){
            os << f.num;
        } else {
            os << f.num << "/" << f.den;
        }
        return os; 
    }
};

template<typename T>
bool Frac<T>::show_denum_if_one = true;

int main() {

    int w = 30; char f = ' ';
    
    cout << endl;

    cout << "Frac(13, 2) :                          " << Frac(13, 2) << endl;
    cout << "Frac(13, 0) :                          " << Frac(13, 0) << endl;
    cout << endl;

    cout << "Frac(13, 7) + Frac(12, 9) :            " << Frac(13, 7) + Frac(12, 9) << endl;
    cout << "Frac(500, 100) + Frac(500, 100) :      " << Frac(500, 100) + Frac(500, 100) << endl;
    cout << endl;

    Frac a(50, 10); a.simplify();
    cout << "Frac a(50, 10); a.simplify(); a :      " << a << endl;
    cout << endl;

    Frac b(16777216, 4194304);
    cout << "Frac b(16777216, 4194304); b :         " << b << endl;
    cout << endl;

    Frac d(5, 1);
    cout << "Frac d(5, 1);                          " << d << endl;
    Frac<int>::show_denum_if_one = false;
    cout << "Frac<int>::show_denum_if_one = false : " << endl;
    cout << "d :                                    " << d << endl;
    cout << endl;

    Frac c(5, 7);
    cout << "Frac c(5, 7); c :                      " << c << endl;
    c.invert();
    cout << "c.invert() :                           " << c << endl;
    c.invert();
    cout << "c.invert() :                           " << c << endl;
    cout << "1.0 / c :                              " << 1.0 / c << endl;
    cout << endl;

    cout << "Frac(1, 1) / Frac(13, 9) :             " << Frac(1, 1) / Frac(13, 9) << endl;
    cout << endl;

    return 0;
}
