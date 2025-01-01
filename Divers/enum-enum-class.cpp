#include <iostream>
using namespace std;
enum color {orange, green, brown};
enum class direction {up, down, right, left};
int main() {
    color carot = orange;
    cout << carot << endl;
    direction earth = direction::left;
    cout << static_cast<int>(earth) << endl;
    return 0;
}