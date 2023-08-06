#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 600010;
ll n, m;
ll a[MAXN], s[MAXN];
ll roots[MAXN];
ll trie[MAXN * 30][2], idx = 0;
ll val[MAXN * 30];
void insert(int cur, int lst, int v) {
  for (int i = 28; i >= 0; --i) {
    val[cur] = val[lst] + 1;
    if ((v & (1 << i)) == 0) {
      if (!trie[cur][0])
        trie[cur][0] = ++idx;
      trie[cur][1] = trie[lst][1];
      cur = trie[cur][0];
      lst = trie[lst][0];
    } else {
      if (!trie[cur][1])
        trie[cur][1] = ++idx;
      trie[cur][0] = trie[lst][0];
      cur = trie[cur][1];
      lst = trie[lst][1];
    }
  }
  val[cur] = val[lst] + 1;
}
ll query(ll l, ll r, ll v) {
  ll res = 0;
  for (int i = 28; i >= 0; --i) {
    auto tmp = ((v & (1 << i)) == 0 ? 1 : 0);
    if (val[trie[l][tmp]] != val[trie[r][tmp]]) {
      res += (1 << i);
      l = trie[l][tmp];
      r = trie[r][tmp];
    } else {
      l = trie[l][!tmp];
      r = trie[r][!tmp];
    }
  }
  return res;
}
int main() {
  char op;
  ll l, r, x;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = a[i] ^ s[i - 1];
    roots[i] = ++idx;
    insert(roots[i], roots[i - 1], s[i]);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> op;
    if (op == 'A') {
      cin >> a[++n];
      s[n] = a[n] ^ s[n - 1];
      roots[n] = ++idx;
      insert(roots[n], roots[n - 1], s[n]);
    } else {
      cin >> l >> r >> x;
      if (l == 1)
        cout << max(query(roots[r - 1], roots[l - 2], s[n] ^ x), s[n] ^ x)
             << endl;
      else
        cout << query(roots[r - 1], roots[l - 2], s[n] ^ x) << endl;
    }
  }

  return 0;
}
/**
5 5
2 6 4 3 6
A 1
Q 3 5 4
A 4
Q 5 7 0
Q 3 6 6
**/