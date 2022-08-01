#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MAXM = 100010;
const ll MAXA = 1000010;
ll n, m;
ll a[MAXN];
ll cnt[MAXA], ans[MAXA];
ll res = 0;
int main() {
  ll x, y;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    if (cnt[a[i]] == 3) {
      res++;
      ans[a[i]] = 1;
    } else if (cnt[a[i]] > 3) {
      res = res + (ans[a[i]] * cnt[a[i]] / (cnt[a[i]] - 3) - ans[a[i]]);
      ans[a[i]] = ans[a[i]] * cnt[a[i]] / (cnt[a[i]] - 3);
    }
  }
  while (m--) {
    cin >> x >> y;
    if (cnt[a[x]] == 3) {
      res--;
      ans[a[x]] = 0;
    } else if (cnt[a[x]] > 3) {
      res = res - (ans[a[x]] - ans[a[x]] * (cnt[a[x]] - 3) / cnt[a[x]]);
      ans[a[x]] = ans[a[x]] * (cnt[a[x]] - 3) / cnt[a[x]];
    }
    cnt[a[x]]--;
    a[x] = y;
    cnt[a[x]]++;
    if (cnt[a[x]] == 3) {
      res++;
      ans[a[x]] = 1;
    } else if (cnt[a[x]] > 3) {
      res = res + (ans[a[x]] * cnt[a[x]] / (cnt[a[x]] - 3) - ans[a[x]]);
      ans[a[x]] = ans[a[x]] * cnt[a[x]] / (cnt[a[x]] - 3);
    }
    cout << res << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}