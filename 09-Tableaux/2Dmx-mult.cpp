#include <iostream>
#include <vector>
using namespace std;

using Matrix2D = vector<vector<int>>;

Matrix2D matrix2D_mult(Matrix2D a, Matrix2D b) {
    int ax = a[0].size();
    int ay = a.size();
    int bx = b[0].size();
    int by = b.size();
    Matrix2D m(ay, vector<int>(bx, 0));
    if(ax != by) {
        cout << "Matrice sizes not valid: matrix a columns / y not equal matrix b row / x" << endl;
    } else {
        for(int k = 0; k < ay * bx; ++k) {
            for(int s = 0; s < ax; ++s) {
                int row = k / bx;
                int col = k % bx;
                m[row][col] += a[row][s] * b[s][col];
            }
        }
    }
    return m;
}

void print_matrix2D(Matrix2D m) {
    for(vector<int>& v : m) {
        for(int a : v) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    Matrix2D matrix_one = {
        {0, 1, 2},
        {2, 1, 0},
        {2, 1, 0},
        {0, 0, 0},
        {0, 2, 0},
        {0, 0, 0},
        {0, 1, 2}
        };

    Matrix2D matrix_two = {
        {0, 1, 2, 1, 2, 0, 0},
        {0, 1, 0, 1, 0, 1, 1},
        {2, 1, 0, 0, 1, 0, 0}
        };

    print_matrix2D(matrix_one);
    print_matrix2D(matrix_two);    
    Matrix2D matrix_one_by_matrix_two = matrix2D_mult(matrix_one, matrix_two);
    print_matrix2D(matrix_one_by_matrix_two);    

    return EXIT_SUCCESS;
}