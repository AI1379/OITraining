#include <stdio.h>
static int a, b;
int main() {
  scanf("%d", &a);
#ifdef BIT_
  b = a >> 1;
#else
  b = a / 2;
#endif
  printf("%d\n", b);
  return 0;
}