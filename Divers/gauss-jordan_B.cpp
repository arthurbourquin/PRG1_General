// quelle merde...

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>
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
        } else if(denominator == 1) {
            cout << setfill(' ') << setw(5) << numerator ;
        } else {
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

    Frac & operator = (long long rhs) {
        (*this).numerator = rhs;
        (*this).denominator = 1;
        (*this).is_undefined = false;
        return (*this);
    }

    friend ostream & operator << (ostream & os, const Frac & f);
};

ostream & operator << (ostream & os, const Frac & f) {
    if(f.denominator == 1) {
        os << f.numerator;
    } else {
        os << f.numerator << "/" << f.denominator;
    }
    return os;
}

template<typename T>
class Gauss_Matrix {
public:
    vector<vector<Frac>> Matrix;
    vector<int> Leading_zeros;
    vector<bool> Ordered;
    bool Echlonned;
    bool Reduced;

    Gauss_Matrix(vector<vector<T>> init_m) :
        Matrix(init_m),
        Ordered(false),
        Reduced(false) {
            // initalisation de la matrice augmentée
            Matrix.push_front(vector<Frac>(init_m.at(0).size(), 1));
            // ajout d'une colonne représentant le nombre de zéros en début de ligne
            for(size_t i = 0; i < Matrix.at(0).size(); ++i) {
                for(long long j = 0; j < Matrix.at(i).size(); ++j) {
                    if(Matrix.at(i).at(j) != 0) {
                        Matrix.at(i).push_back(j);
                        break;
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

    void add_line(size_t moded_line, size_t moder_line, Frac factor) {
        moded_line--; moder_line--; // L1 = Matrix.at(0)
        for(size_t i = 0; i < Matrix.at(0).size(); ++i) {
            Matrix.at(moded_line).at(i) = Matrix.at(moded_line).at(i) + Matrix.at(moder_line).at(i) * factor;
        }
        Dir_Vec.at(moded_line) = Dir_Vec.at(moded_line) + Dir_Vec.at(moder_line) * factor;
        update_matrix();
    }

    void subtract_line(size_t moded_line, size_t moder_line, Frac factor) {
        moded_line--; moder_line--; // L1 = Matrix.at(0)
        for(size_t i = 0; i < Matrix.at(0).size(); ++i) {
            Matrix.at(moded_line).at(i) = Matrix.at(moded_line).at(i) + Matrix.at(moder_line).at(i) / factor;
        }
        Dir_Vec.at(moded_line) = Dir_Vec.at(moded_line) - Dir_Vec.at(moder_line) * factor;
        update_matrix();
    }

    void multiply_line(size_t moded_line, size_t moder_line, Frac factor) {
        moded_line--; moder_line--; // L1 = Matrix.at(0)
        for(size_t i = 0; i < Matrix.at(0).size(); ++i) {
            Matrix.at(moded_line).at(i) = Matrix.at(moded_line).at(i) * Matrix.at(moder_line).at(i) * factor;
        }
        Dir_Vec.at(moded_line) = Dir_Vec.at(moded_line) * Dir_Vec.at(moder_line) * factor;
        update_matrix();
    }

    void divide_line(size_t moded_line, size_t moder_line, Frac factor) {
        moded_line--; moder_line--; // L1 = Matrix.at(0)
        for(size_t i = 0; i < Matrix.at(0).size(); ++i) {
            Matrix.at(moded_line).at(i) = (Matrix.at(moded_line).at(i) / Matrix.at(moder_line).at(i)) * factor;
        }
        Dir_Vec.at(moded_line) = (Dir_Vec.at(moded_line) / Dir_Vec.at(moder_line)) * factor;
        update_matrix();
    }

    Frac get_element(size_t line, size_t row) {
        return Matrix.at(line).at(row);
    }

    void print() const {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            cout << "L" << setfill(' ') << setw(5) << i + 1 << " [ ";
            for(size_t j = 0; j < Matrix.at(i).size(); ++j) {
                Matrix.at(i).at(j).print();
                if(j != Matrix.at(i).size() - 1) cout << " , ";
            }
            cout << "  | ";
            Dir_Vec.at(i).print();
            cout << " ]" << endl;
        }
    }
};

Gauss_Matrix<Frac> gauss_matrix_A( {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9,  0},
    { 3,  8,  2,  5,  4},
    { 1,  1,  1,  1,  1}
    } );


int main() {

    Frac a(3, 4);
    Frac b(4, 3);
    Frac r;
    cout << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a + b: " << a + b << endl;
    cout << "a - b: " << a - b << endl;
    cout << "a * b: " << a * b << endl;
    cout << "a / b: " << a / b << endl;
    cout << endl;
    

    gauss_matrix_A.print();

    while(true) {
        string a, b, c, d;
        short line_a, line_b;
        char op;
        Frac factor;
        cout << endl;
        cout << "------------" << endl;
        cout << "valid operations:  L1 * 3 L0 ,  L1 * 2 L3 ,  L1 * (5/7) L0 ,  L99 * (5/7) L3 ,  ..." << endl;

        try {
            cin >> a; a.erase(0, 1); line_a = stoi(a);

            cin >> b; op = b[0];
            if(!(b[0] == '+' || b[0] == '-' || b[0] == '*' || b[0] == '/')) {
                throw invalid_argument("operator is not an operator + - * /.");
            }

            cin >> c;
            if(isdigit(c[0])) {
                factor = stoi(c);
            } else {
                throw invalid_argument("Line 1 number not a number.");
            }
            if(c[0] == '(') {
                string num_s = "";
                string denom_s = "";
                short i = 0;
                if(!isdigit(c[i])) {
                    throw invalid_argument("Factor numerator is not a number.");
                }
                while(isdigit(c[i])) {
                    num_s += c[i];
                }
                i++;
                if(!isdigit(c[i])) {
                    throw invalid_argument("Factor denominator is not a number.");
                }
                while(isdigit(c[i])) {
                    denom_s += c[i];
                }
                short num = stoi(num_s);
                short denom = stoi(denom_s);
                factor = Frac(num, denom);
            }

            cin >> d; d.erase(0, 1); line_b = stoi(d);

            cout << "operation: L" << line_a << " " << op << " " << factor << " L" << line_b << endl;
            cout << endl;

            if(op == '+') {
                gauss_matrix_A.add_line(line_a, line_b, factor);
                gauss_matrix_A.print();
            }
            if(op == '-') {
                gauss_matrix_A.subtract_line(line_a, line_b, (factor));
                gauss_matrix_A.print();
            }
            if(op == '*') {
                gauss_matrix_A.multiply_line(line_a, line_b, factor);
                gauss_matrix_A.print();
            }
            if(op == '/') {
                gauss_matrix_A.divide_line(line_a, line_b, (factor));
                gauss_matrix_A.print();
            }
        } catch (const invalid_argument & e) {
            cout << "No comprendo la operationes..." << endl;
            cout << e.what() << endl;
        }        
    }

    return 0;
}
