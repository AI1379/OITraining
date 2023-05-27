#include <stdio.h>
static int i, n, cnt;
int main() {
  scanf("%d", &n);
#ifdef XOR_
  for (i = 0; i ^ n; ++i)
#elifdef LESS_
  for (i = 0; i < n; ++i)
#else
  for (i = 0; i != n; ++i)
#endif
    cnt += i;
  printf("%d\n", cnt);
  return 0;
}