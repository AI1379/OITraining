#include <bits/stdc++.h>
using namespace std;
struct A {
  void fun(int &a) { ++a; }
};
struct B {
  int fun2(int &b) { return ++b; }
};
struct C : public A, public B {};
struct D : public A, public B {};
struct E : public A {};
struct F : public B {};

template <typename T,
          typename enable_if<is_base_of_v<A, T> && is_base_of_v<B, T>,
                             bool>::type = true>
void func(T *a) {
  // static_assert(is_base_of_v<A, T> && is_base_of_v<B, T>, "ERROR");
  cout << &a;
}

int main() {
  func(static_cast<C *>(nullptr));
  return 0;
}