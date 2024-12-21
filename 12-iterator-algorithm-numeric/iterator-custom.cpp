#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int> v) {
    vector<int> result;
    for(int* pi = &v.at(v.size() - 1); pi >= &v.at(0); --pi) {
        result.push_back(*pi);
    }
    return result;
}

void print_vector(vector<int> v) {
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    vector<int> victor = {2345, 3245, 2345, 7634, 623652};

    cout << endl;
    print_vector(reverse(victor));
    cout << endl;

    return 0;
}