#include <bits/stdc++.h>
using namespace std;
const int N = 3e7 + 10;

#ifdef __clang__
typedef _BitInt(128) int128_t;
#elifdef __GNUC__
typedef __int128 int128_t;
#endif

typedef unsigned long long ull;
int n, A, B, C, u[N], v[N], w[N];
ull Rand(ull &k1, ull &k2) {
  ull k3 = k1, k4 = k2;
  k1 = k4;
  k3 ^= (k3 << 23);
  k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return k2 + k4;
}
void GetData() {
  ull x, y;
  cin >> n >> A >> B >> C >> x >> y;
  for (int i = 1; i <= n; i++) {
    u[i] = Rand(x, y) % A + 1;
    v[i] = Rand(x, y) % B + 1;
    w[i] = Rand(x, y) % C + 1;
    if (Rand(x, y) % 3 == 0)
      u[i] = A;
    if (Rand(x, y) % 3 == 0)
      v[i] = B;
    if ((u[i] != A) && (v[i] != B))
      w[i] = C;
  }
}
int main() {
  GetData();
  int128_t x;
}