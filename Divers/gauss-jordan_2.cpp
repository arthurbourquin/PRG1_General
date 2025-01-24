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

    Frac(long long init_numerator, long long init_denominator) :
        numerator(init_numerator),
        denominator(init_denominator),
        is_undefined(denominator == 0) {}

    Frac(long long init_frac) : 
        numerator(init_frac),
        denominator(1),
        is_undefined(false) {}

    void print() const {
        if(is_undefined) {
            cout << "inf" << endl;
        } else{
            cout << numerator << "/" << denominator << endl;
        }
    }

    void simplify() {
        if(denominator == 0) {
            numerator = 0;
            denominator = 0;
            is_undefined = true;
        } else {
            for(size_t i = 1000; i > 0; --i) {
                cout << i << endl;
                if(numerator % i == 0 && denominator % i == 0) {
                    numerator /= i;
                    denominator /= i;
                    break;
                }
                print();
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

    bool operator == (Frac rhs) const {
        simplify();
        rhs.simplify();
        if(is_undefined && rhs.is_undefined) return true;
        if(is_undefined || rhs.is_undefined) return false;
        if(numerator == rhs.numerator && denominator == rhs.denominator) return true;
        return false;
    }

    bool operator != (const Frac & rhs) const {
        if(!((*this) == rhs)) {
            return true;
        } else {
            return false;
        }
    }
};

class Gauss_Matrix {
public:
    vector<vector<Frac>> Matrix;
    vector<Frac> Dir_Vec;
    vector<int> Leading_zeros;
    vector<bool> Ordered;
    bool Echlonned;
    bool Reduced;
    Gauss_Matrix(vector<vector<Frac>> init_gauss_matrix) :
        Matrix(init_gauss_matrix),
        Dir_Vec(init_gauss_matrix.size()),
        Leading_zeros(init_gauss_matrix.size()),
        Ordered(false),
        Reduced(false)
        {
            for(size_t i = 0; i < Matrix.size(); ++i) {
                // initialize direction vector (last value fo user input)
                Dir_Vec.at(i) = Matrix.at(i).at(Matrix.at(i).size() - 1);
                // remove last value of Matrix (which was for direction vector)
                Matrix.at(i).resize(Matrix.size() - 1);
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

    void print() const {
        for(size_t i = 0; i < Matrix.size(); ++i) {
            cout << "[ ";
            for(size_t j = 0; j < Matrix.at(i).size(); ++j) {
                Matrix.at(i).at(j).print();
                if(j != Matrix.at(i).size() - 1) cout << ", ";
            }
            cout << " | ";
            Dir_Vec.at(i).print();
            cout << " ]" << endl;
        }
        cout << endl;
    }
};

template<typename T>
Gauss_Matrix to_Gauss_Matrix(const vector<vector<T>> & m) {
    size_t row = m.size();
    size_t col = m.at(0).size();
    vector<vector<Frac>> result(row, vector<Frac>(col, 0));
    for(size_t i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            result[i][j] = Frac(m[i][j]);
        }
    }
    return result;
}


vector<vector<int>> gauss_matrix_A_init = {
    {-1,  1, -1,  1,  1},
    { 3, -2,  1,  0,  2},
    { 1,  1,  1,  1,  0},
    { 3,  2,  1,  0,  1}
};
Gauss_Matrix gauss_matrix_A = to_Gauss_Matrix(gauss_matrix_A_init);


void print_line(const vector<double> & line) {
    cout << "[ ";
    for(size_t i = 0; i < line.size(); ++i) {
        cout << setfill(' ') << setw(4) << line.at(i);
        if(i < line.size() - 2) cout << " , ";
        if(i == line.size() - 2) cout << " | ";
    }
    cout << " ]" << endl;
}

void print_augmented_matrix(const Augmented_Matrix & AG) {
    for(int i = 0; i < AG.size(); ++i) {
        print_line(AG.at(i));
    }
    cout << endl;
}

void invert_line(Augmented_Matrix & AG, int line) {
    for(size_t i = 0; i < AG.at(line).size(); ++i) {
        AG.at(line).at(i) *= -1;
    }
}

void subtract_line(Augmented_Matrix & AG, double rhs_line, double lhs_line, double factor) {
    for(size_t i = 0; i < AG.at(rhs_line).size(); ++i) {
        AG.at(rhs_line).at(i) -= AG.at(lhs_line).at(i) * factor;
    }
}

int main() {

    Frac ouais(773, 14341);
    Frac super(3);
    ouais.print();
    ouais.simplify();
    ouais.print();


    print_augmented_matrix(augmented_matrix_A);
    invert_line(augmented_matrix_A, 0);
    print_augmented_matrix(augmented_matrix_A);
    subtract_line(augmented_matrix_A, 1, 2, 3);
    print_augmented_matrix(augmented_matrix_A);

    return 0;
}
