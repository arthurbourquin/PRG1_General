// quelle merde...

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class Frac {
public:
    long long numerator;
    long long denominator;
    bool is_undefined;

    Frac() : numerator(1), denominator(1), is_undefined(false) {}

    Frac(long long init_numerator, long long init_denominator) :
        numerator(init_numerator),
        denominator(init_denominator),
        is_undefined(denominator == 0) {}

    Frac(long long init_frac) : 
        numerator(init_frac),
        denominator(1),
        is_undefined(false) {}

    Frac(const Frac & f) :
        Frac(f.numerator, f.denominator) {}

    void print() const {
        if(is_undefined) {
            cout << "inf";
        } else{
            cout << setfill(' ') << setw(5) << numerator << "/" << denominator;
        }
    }

    void simplify() {
        if(denominator == 0) {
            numerator = 0;
            denominator = 0;
            is_undefined = true;
        } else {
            for(size_t i = 1000; i > 0; --i) {
                if(numerator % i == 0 && denominator % i == 0) {
                    numerator /= i;
                    denominator /= i;
                    break;
                }
            }
        }
    }

    Frac operator + (const Frac & rhs) {
        if(is_undefined || rhs.is_undefined) {
            return Frac(1, 0);
        } else {
            long long numerator_result = numerator * rhs.denominator + denominator * rhs.numerator;
            long long denominator_result = denominator * rhs.denominator;
            Frac result(numerator_result, denominator_result);
            result.simplify();
            return result;
        }
    }

    Frac operator - (const Frac & rhs) {
        if(is_undefined || rhs.is_undefined) {
            return Frac(1, 0);
        } else {
            long long numerator_result = numerator * rhs.denominator - denominator * rhs.numerator;
            long long denominator_result = denominator * rhs.denominator;
            Frac result(numerator_result, denominator_result);
            result.simplify();
            return result;
        }
    }

    Frac operator * (const Frac & rhs) {
        if(is_undefined || rhs.is_undefined) {
            return Frac(1, 0);
        } else {
            Frac result(numerator * rhs.numerator, denominator * rhs.denominator);
            result.simplify();
            return result;
        }
    }

    Frac operator / (const Frac & rhs) {
        if(is_undefined || rhs.is_undefined) {
            return Frac(1, 0);
        } else {
            Frac result(numerator * rhs.denominator, denominator * rhs.numerator);
            result.simplify();
            return result;
        }
    }

    bool operator == (Frac rhs) {
        simplify();
        rhs.simplify();
        if(is_undefined && rhs.is_undefined) return true;
        if(is_undefined || rhs.is_undefined) return false;
        if(numerator == rhs.numerator && denominator == rhs.denominator) return true;
        return false;
    }

    bool operator != (const Frac & rhs) {
        if(!((*this) == rhs)) {
            return true;
        } else {
            return false;
        }
    }

    Frac & operator = (const Frac & rhs) {
        (*this).numerator = rhs.numerator;
        (*this).denominator = rhs.denominator;
        (*this).is_undefined = rhs.is_undefined;
        return (*this);
    }
};

template<typename T>
class Gauss_Matrix {
public:
    vector<vector<T>> Matrix_T;
    vector<vector<Frac>> Matrix;
    vector<Frac> Dir_Vec;
    vector<int> Leading_zeros;
    vector<bool> Ordered;
    bool Echlonned;
    bool Reduced;

    Gauss_Matrix(vector<vector<T>> init_gauss_matrix) :
        Matrix_T(init_gauss_matrix),
        Matrix(init_gauss_matrix.size(), vector<Frac>(init_gauss_matrix.at(0).size())),
        Dir_Vec(init_gauss_matrix.size()),
        Leading_zeros(init_gauss_matrix.size()),
        Ordered(false),
        Reduced(false) {
            for(size_t i = 0; i < Matrix_T.size(); ++i) {
                for(size_t j = 0; j < Matrix_T.at(0).size(); ++j) {
                    Matrix[i][j] = Frac(Matrix_T[i][j]);
                }
            }
            for(size_t i = 0; i < Matrix.size(); ++i) {
                // initialize direction vector (last value fo user input)
                Dir_Vec.at(i) = Frac(Matrix.at(i).at(Matrix.at(i).size() - 1));
                // remove last value of Matrix (which was for direction vector)
                Matrix.at(i).pop_back();
                // define leading zero(s)
                for(size_t k = 0; k < Matrix.at(i).size(); ++k) {
                    if(Matrix.at(i).at(k) != 0) {
                        Leading_zeros.at(i) = k;
                        break;
                    }
                }
                // define if line is ordered
                // - more leading 0 than previous
                // - less leading 0 than next
                for(size_t j = 0; j < Matrix.at(i).size(); ++j) {
                }
            }
        }

    void update_matrix() {
        simplify_matrix();
        update_leading_zeros();
    }
    void simplify_matrix() {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            for(size_t j = 0; j < Matrix.at(i).size(); ++j) {
                Matrix.at(i).at(j).simplify();
            }
        }
    }
    void update_leading_zeros() {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            for(size_t j = 0; j < Matrix.at(i).size(); ++j) {
                Leading_zeros.at(i) = 0;
                if(Matrix.at(i).at(j).numerator == 0) {
                    Leading_zeros.at(i)++;
                } else {
                    break;
                }
            }
        }
    }

    void multiply_line(size_t moded, long long factor) {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            Matrix.at(moded).at(i) = Matrix.at(moded).at(i) * factor;
        }
        Dir_Vec.at(moded) = Dir_Vec.at(moded) * factor;
        update_matrix();
    }

    void multiply_line(size_t moded, size_t moder, long long factor) {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            Matrix.at(moded).at(i) = Matrix.at(moded).at(i) * Matrix.at(moder).at(i) * factor;
        }
        Dir_Vec.at(moded) = Dir_Vec.at(moded) * Dir_Vec.at(moder) * factor;
        update_matrix();
    }

    void add_line(size_t moded, long long addor) {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            Matrix.at(moded).at(i) = Matrix.at(moded).at(i) + addor;
        }
        Dir_Vec.at(moded) = Dir_Vec.at(moded) + addor;
        update_matrix();
    }

    void add_line(size_t moded, size_t moder, long long addor) {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            Matrix.at(moded).at(i) = Matrix.at(moded).at(i) * Matrix.at(moder).at(i) + addor;
        }
        Dir_Vec.at(moded) = Dir_Vec.at(moded) * Dir_Vec.at(moder) + addor;
        update_matrix();
    }

    Frac get_element(size_t line, size_t row) {
        return Matrix.at(line).at(row);
    }

    void print() const {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            cout << "[ ";
            for(size_t j = 0; j < Matrix.at(i).size(); ++j) {
                Matrix.at(i).at(j).print();
                if(j != Matrix.at(i).size() - 1) cout << " , ";
            }
            cout << "  | ";
            Dir_Vec.at(i).print();
            cout << " ]" << endl;
        }
        cout << endl;
    }
};

int main() {

    Gauss_Matrix<Frac> gauss_matrix_A( {
        {-1,  1, -1,  1,  1},
        { 3, -2,  1,  0,  2},
        { 1,  1,  1,  1,  0},
        { 3,  2,  1,  0,  1}
        } );

    Frac a(2, 5);
    Frac b(7, 3);
    Frac result;
    result = a + b;
    cout << result.numerator << "/" << result.denominator << endl;
    result = a - b;
    cout << result.numerator << "/" << result.denominator << endl;
    result = a * b;
    cout << result.numerator << "/" << result.denominator << endl;
    result = a / b;
    cout << result.numerator << "/" << result.denominator << endl;

    gauss_matrix_A.print();
    gauss_matrix_A.multiply_line(1, 0, 2);
    gauss_matrix_A.print();
    gauss_matrix_A.multiply_line(2, 0);
    gauss_matrix_A.print();

    return 0;
}
