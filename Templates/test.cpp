#include <bits/stdc++.h>
using namespace std;
class A {
public:
  int count(int y) {
    static int counter = 0;
    counter += y;
    cout << counter << endl;
    return counter;
  }
};
int main() {
  A a;
  auto bptr = new A;
  a.count(1);
  bptr->count(1);
  a.count(3);
  return 0;
}