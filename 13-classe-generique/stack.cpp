#include <iostream>
#include <array>
using namespace std;

template<typename T, size_t n = 100>
class Stack {
   size_t size;
   array<T, n> data;
public:
Stack() : size(0), data() {};
   void push(int elm) {
      if (full()) return;
      data[size] = elm;
      ++size;
   }
   void pop() {
   if (empty()) return;
      --size;
   }
   int top() const {
      if (empty()) return INT_MIN;
      return data[size - 1];
   }
   bool full() const {
      return size == data.size();
   }
   bool empty() const {
      return size == 0;
   }
   size_t size_of() const {
      return size;
   }
   void display() const {
      cout << "size : " << size << endl;
      cout << "data : ";
      cout << "[";
      for (size_t i = 0; i < size; ++i) {
         if(i) cout << ", ";
         cout << data[i];
      }
      cout << "]" << endl;
   }
   string operator()(Stack s) {
      stringstream ss;
      ss << "size: " << size << "\ndata: " << 
      return ss.string();
   }
};


using namespace std;

int main() {

   Stack<int, 10> s;
   int i = 1;

   s.display();
   cout << endl;

   while (! s.full()) {
      s.push(i*=2);
   }

   cout << "top  : " << s.top() << endl;
   cout << "size : " << s.size_of() << endl;
   cout << endl;

   s.display();
   cout << endl;

   while (! s.empty()) {
      s.pop();
   }

   s.display();
   cout << endl;

   Stack<int, 10> s2;
   for (int i=0; i<6; ++i) {
      s.push(i);
   }

   // cast Stack<T, n> => string
   cout << string(s2) << endl;

   // constructeur par copie
   Stack copie(s2);

   // opérateur de flux <<
   cout << copie     << endl;

   // opérateur ==
   cout << boolalpha << (s2 == copie) << endl;

   return 0;
}