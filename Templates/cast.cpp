#include <cstdio>
int a;
long long b;
int main() {
  scanf("%d", &a);
#ifdef CAST_
  b = static_cast<int>(a);
#else
  b = (int)(a);
#endif
  printf("%lld", b);
  return 0;
}