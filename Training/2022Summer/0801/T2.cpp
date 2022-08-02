#include<iostream>
using namespace std;
#define ll long long
const ll MAXN = 200010; 
ll n, m;
ll a[MAXN];
ll beg[MAXN];
ll last[MAXN], len[MAXN];
ll logn[MAXN];
ll st[MAXN][20];
void prebuild() {
  logn[1] = 0;
  logn[2] = 1;
  for (int i = 3; i <= n; i++) {
    logn[i] = logn[i / 2] + 1;
  }
  for (int i = 1; i <= n; i++) {
    st[i][0] = len[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}
inline ll query_rmq(ll l, ll r) {
  ll s = logn[r - l + 1];
  return max(st[l][s], st[r - (1 << s) + 1][s]);
}
ll query(ll l, ll r) {
  ll res;
  ll s, t, mid;
  s = l, t = r;
  while (s < t) {
    mid = (s + t) / 2;
    if (beg[mid] < l) {
      s = mid + 1;
    } else {
      t = mid;
    }
  }
  if (s == r) {
    return r - l + 1;
  }
  res = query_rmq(s + 1, r);
  res = max(res, s - l + 1);
  return res;
}
int main() {
  ll l, r;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    beg[i] = max(beg[i - 1], last[a[i]] + 1);
    last[a[i]] = i;
    len[i] = i - beg[i] + 1;
  }
  prebuild();
  while (m--) {
    cin >> l >> r;
    cout << query(l + 1, r + 1) << endl;
  }
  return 0;
}
