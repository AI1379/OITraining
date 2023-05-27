#include <cstdio>
struct A {
  int x;
};

static A a, b, c;

#ifdef OPERATOR_
A operator+(const A &lhs, const A &rhs) {
  static A res;
  res.x = lhs.x + rhs.x;
  return res;
}
#else
A pl(const A &lhs, const A &rhs) {
  static A res;
  res.x = lhs.x + rhs.x;
  return res;
}
#endif

int main() {
  scanf("%d%d", &a.x, &b.x);
#ifdef OPERATOR_
  c = a + b;
#else
  c = pl(a, b);
#endif
  printf("%d\n", c.x);
  return 0;
}