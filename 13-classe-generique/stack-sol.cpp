#include <iostream>
#include <array>

//---------------------------------------------------------
using Data = std::array<int, 10>;
struct Stack {
   size_t size = 0;
   Data   data = {};
};

//---------------------------------------------------------

void   push     (      Stack& s, int  v);
void   pop      (      Stack& s);
int    top      (const Stack& s);
bool   full     (const Stack& s);
bool   empty    (const Stack& s);
size_t size     (const Stack& s);
void   display  (const Stack& s);

//---------------------------------------------------------

using namespace std;

int main() {

   Stack s;
   int i = 1;

   display(s);
   cout << endl;

   while (not full(s)) {
      push(s, i*=2);
   }

   cout << "top  : " << top(s) << endl;
   cout << "size : " << size(s) << endl;
   cout << endl;

   display(s);
   cout << endl;

   while (not empty(s)) {
      pop(s);
   }

   display(s);
   cout << endl;
}

//---------------------------------------------------------

void push(Stack& s, int v) {
//   if (full(s)) return;
   s.data[s.size] = v;
   ++s.size;
}

void pop(Stack& s) {
//   if (empty(s)) return;
   --s.size;
}

int top(const Stack& s) {
//   if (empty(s)) return INT_MIN;
   return s.data[s.size - 1];
}

bool full(const Stack& s) {
   return s.size == s.data.size();
}

bool empty(const Stack& s) {
   return s.size == 0;
}

size_t size(const Stack& s) {
   return s.size;
}

void display(const Stack& s) {
   cout << "size : " << s.size << endl;
   cout << "data : ";

   cout << "[";
   for (size_t i = 0; i < s.size; ++i) {
      if(i) cout << ", ";
      cout << s.data[i];
   }
   cout << "]" << endl;
}