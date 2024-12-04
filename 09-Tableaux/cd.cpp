#include <iostream>
#include <vector>
using namespace std;
using Matrix2D = vector<vector<int>>;

Matrix2D cadre_diagonale(int n) {
    Matrix2D result(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == 0 || i == n -1 || j == 0 || j == n -1 || i == j) {
                result[i][j] = 1;
            }
        }
    }
    return result;
}

void print(Matrix2D m) {
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < m[i].size(); ++j) {
            cout << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    print(cadre_diagonale(4));
    print(cadre_diagonale(5));
    return EXIT_SUCCESS;
}