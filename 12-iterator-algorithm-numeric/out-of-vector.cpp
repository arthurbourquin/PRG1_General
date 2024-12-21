#include <iostream>
#include <vector>

using namespace std;

void endl() {
    cout << endl;
}

void print_vector(vector<int> hector) {
    for(int i : hector) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

void print_vector_and_10_more(vector<int>& hector) {
    for (int i = 0; i < hector.size() + 10; ++i) {
    cout << &hector[i]  << "\t" << &hector[i] - &hector[0] << "\t" << hector[i] << "\t";
    if(i < hector.size()) {
        cout << " is in vector";
    } else {
        cout << " is out of vector";
    }
    cout << endl;
    }
    cout << endl;
}

vector<int> vector_manipulation_copy(vector<int> hector) {
    for(int i : hector) {
        i++;
    }
    return hector;
}

void vector_manipulation_itself(vector<int>& hector) {
    for(int i : hector) {
        i++;
    }
}

int main() {

    vector<int> victor = {2345, 3245, 2345, 7634, 623652};

    endl();

    print_vector_and_10_more(victor);

    vector_manipulation_copy(victor);

    print_vector_and_10_more(victor);

    vector_manipulation_itself(victor);

    print_vector_and_10_more(victor);

    endl();

    return 0;
}