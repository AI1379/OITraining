#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 100;
struct tie {
  int len, place;
} A[N];
int n, B[N], f[N], g[N], Ans[N];
inline int max(int x, int y) { return x > y ? x : y; }
inline bool cmp(tie x, tie y) { return x.len < y.len; }
inline int read() {
  int an(0), ch(getchar());
  for (; ch < 48 || ch > 57; ch = getchar())
    ;
  for (; ch > 47 && ch < 58; ch = getchar())
    an = (an << 3) + (an << 1) + ch - 48;
  return an;
}
int main() {
  n = read();
  for (int i(1); i <= n + 1; i++) {
    A[i].len = read();
    A[i].place = i;
  }
  sort(A + 1, A + n + 2, cmp);
  for (int i(1); i <= n; i++) B[i] = read();
  sort(B + 1, B + n + 1);
  for (int i(1); i <= n; i++) f[i] = max(f[i - 1], max(A[i].len - B[i], 0));
  for (int i(n); i; i--) g[i] = max(g[i + 1], max(A[i + 1].len - B[i], 0));
  for (int i(1); i <= n + 1; i++) Ans[A[i].place] = max(f[i - 1], g[i]);
  for (int i(1); i <= n + 1; i++) printf("%d ", Ans[i]);
  return 0;
}
