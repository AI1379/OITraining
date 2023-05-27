#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 510;
ll n, k;
char seq[MAXN];
ll dp[MAXN][MAXN];
int main() {
  scanf("%lld%lld", &n, &k);
  scanf("%s", seq + 1);
  for (int d = 1; d <= n; ++d) {
    for (int i = 1, j; i + d <= n; ++i) {
      j = i + d;

    }
  }
  return 0;
}