#include <bits/stdc++.h>
using namespace std;
long long n, t, ans;
long long per[100000];
void solve() {
  ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) per[i] = i;
  do {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j < i; j++)
        if (per[j] > per[i]) ans = (ans + 1) % 998244353;
  } while (next_permutation(per + 1, per + n + 1));
  cout << ans << endl;
}
int main() {
  cin >> t;
  while (t--) solve();
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}