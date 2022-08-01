#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
#define ll long long
const ll MAXK = 1010;
ll t;
ll n;
ll a[MAXK], b[MAXK], p[MAXK];
ll exgcd(ll v1, ll v2, ll &x, ll &y) {
  if (v2 == 0) {
    x = 1;
    y = 0;
    return v1;
  }
  ll res = exgcd(v2, v1 % v2, x, y);
  ll tmp = x;
  x = y;
  y = tmp - y * (v1 / v2);
  return res;
}
ll calc(int pos) {
  ll sub = 1, sum = 0;
  ll mod = p[pos];
  for (int i = 1; i <= pos; i++) {
    sub = sub * a[i] % mod;
    sum = (a[i] * sum % mod + b[i]) % mod;
  }
  ll d, x, y;
  if (sub == 0 && sum!=0)
    return -1;
  else if (sub == 0 && sum == 0)
    return -2;
  d = exgcd(sub, mod, x, y);
  x = x * (mod - sum);
  x = (x % mod + mod) % mod;
#ifdef DEBUG
  cout << "pos: " << pos << ' ' << sub << ' ' << sum << endl;
  cout << "sol: " << d << ' ' << mod - sum << ' ' << x << endl;
#endif
  if (d != 1) {
    x = x % (mod / d);
  }
  if ((mod - sum) % d != 0)
    return -1;
  else
    return x;
}
pair<ll, ll> tmp[MAXK];
ll cnt = 0;
void solve() {
  cnt = 0;
  fill(tmp, tmp + MAXK, make_pair(0, 0));
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  ll res;
  // 处理a=0的情况
  for (int i = 1; i <= n; i++) {
    res = calc(i);
    if (res == -1) {
#ifdef DEBUG
      cout << "No sol" << endl;
#endif
      cout << "No" << endl;
      return;
    } else if (res == -2) {
      continue;
    }
    tmp[cnt++] = make_pair(p[i], res);
  }
  sort(tmp, tmp + cnt);
#ifdef DEBUG
  for (int i = 0; i < cnt; i++) {
    cout << tmp[i].first << ' ' << tmp[i].second << endl;
  }
#endif
  ll ed = unique(tmp, tmp + cnt) - tmp;
  for (int i = 0; i < ed; i++) {
#ifdef DEBUG
    cout << tmp[i].first << ' ' << tmp[i].second << endl;
#endif
    if (tmp[i].first == tmp[i + 1].first &&
        tmp[i].second != tmp[i + 1].second && i + 1 != ed) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}