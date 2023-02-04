#include <iostream>
using namespace std;

void f(const int& x) {
  int& y = const_cast<int&>(x);
  ++y;
}

int main() {
  int a = 5;
  f(a);
  cout << a << endl;
}