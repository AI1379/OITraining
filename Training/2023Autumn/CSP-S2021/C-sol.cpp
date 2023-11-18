#include <cstdio>
int n;
char res[1000005];
int a[1000005];
inline int read() {
  int x = 0, f = 1;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-')
      f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline bool work(int l1, int r1, int l2, int r2) {
  for (int i = 1; i < n; ++i) {
    if (l1 <= r1 &&
        ((l2 <= r2 && a[l1] == a[l2]) || (l1 < r1 && a[l1] == a[r1]))) {
      if (l1 < r1 && a[l1] == a[r1]) {
        ++l1;
        --r1;
        res[i] = 'L';
        res[2 * (n - 1) - i + 1] = 'L';
      } else {
        ++l1;
        ++l2;
        res[i] = 'L';
        res[2 * (n - 1) - i + 1] = 'R';
      }
    } else if (l2 <= r2 &&
               ((l1 <= r1 && a[r2] == a[r1]) || (l2 < r2 && a[l2] == a[r2]))) {
      if (l2 < r2 && a[l2] == a[r2]) {
        ++l2;
        --r2;
        res[i] = 'R';
        res[2 * (n - 1) - i + 1] = 'R';
      } else {
        --r2;
        --r1;
        res[i] = 'R';
        res[2 * (n - 1) - i + 1] = 'L';
      }
    } else {
      return 0;
    }
  }
  return 1;
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    int p1 = -1, p2 = -1;
    for (int i = 1; i <= 2 * n; ++i)
      a[i] = read();
    for (int i = 1; i <= 2 * n + 1; ++i)
      res[i] = 0;
    for (int i = 2; i <= 2 * n; ++i) {
      if (a[1] == a[i]) {
        p1 = i;
        break;
      }
    }
    for (int i = 1; i < 2 * n; ++i) {
      if (a[2 * n] == a[i]) {
        p2 = i;
        break;
      }
    }
    if (work(2, p1 - 1, p1 + 1, 2 * n)) {
      printf("L%sL\n", res + 1);
    } else if (work(1, p2 - 1, p2 + 1, 2 * n - 1)) {
      printf("R%sL\n", res + 1);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
