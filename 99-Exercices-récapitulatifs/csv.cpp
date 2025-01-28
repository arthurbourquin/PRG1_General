#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class File_not_found {};

void display_csv(const string & file_name, char delim, size_t width) {

    fstream file(file_name, ios::in);
    if(!file.is_open()) throw File_not_found{};

    string line = "";
    while(getline(file, line)) {
        string cell = "";
        for(size_t i = 0; i < line.size(); ++i) {
            if(line[i] != delim) {
                cell += line[i];
            } else {
                cout << setw(width) << setfill(' ') << cell;
                cell.clear();
            }
        }
        cout << endl;
    }
}

int main() {
   try {
      display_csv("data.txt", ',', 10);
   } catch (File_not_found & e) {
      cerr << "File not found \n";
      exit(-1);
   }
}
/*
avec `data.txt` qui contient 
hello,world,x,y,z
1,2,,4,5
,b,c,,d

     hello     world         x         y         z
         1         2                   4         5
                   b         c                   d
*/