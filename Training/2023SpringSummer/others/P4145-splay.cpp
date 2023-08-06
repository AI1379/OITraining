#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, q;
ll fa[MAXN];
ll spl[MAXN][2];
ll val[MAXN], s[MAXN], m[MAXN], rt;
bool get(ll u) { return u == spl[fa[u]][1]; }
void pushup(ll u) {
  s[u] = s[spl[u][0]] + s[spl[u][1]] + val[u];
  m[u] = max(val[u], max(m[spl[u][0]], m[spl[u][1]]));
}
/**
void rotate(int x) {
  int y = fa[x], z = fa[y], chk = get(x);
  ch[y][chk] = ch[x][chk ^ 1];
  if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
  ch[x][chk ^ 1] = y;
  fa[y] = x;
  fa[x] = z;
  if (z) ch[z][y == ch[z][1]] = x;
  maintain(y);
  maintain(x);
}

**/
void rotate(ll u) {
  ll v = fa[u], w = fa[v], k = get(u);
  spl[v][k] = spl[u][!k];
  if (spl[u][!k])
    fa[spl[u][!k]] = v;
  spl[u][!k] = v;
  fa[v] = u;
  fa[u] = w;
  if (w)
    spl[w][v == spl[w][1]] = u;
  pushup(v);
  pushup(u);
}
void splay(ll u, ll f) {
  for (ll p = fa[u]; (p && p != f); p = fa[u]) {
    if (fa[p] && fa[p] != f)
      rotate(get(u) == get(p) ? p : u);
    rotate(u);
  }
  if (!f)
    rt = u;
}
ll build(ll l, ll r) {
  ll mid = (l + r) / 2;
  // cout << l << ' ' << mid << ' ' << r << endl;
  if (l > r)
    return 0;
  else if (l == r)
    return mid;
  spl[mid][0] = build(l, mid - 1);
  spl[mid][1] = build(mid + 1, r);
  pushup(mid);
  fa[spl[mid][0]] = fa[spl[mid][1]] = mid;
  return mid;
}
void modify(ll u) {
  if (!u)
    return;
  val[u] = int(sqrt(val[u]));
  modify(spl[u][0]);
  modify(spl[u][1]);
  pushup(u);
}
int main() {
  ll opt, x, y, r;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i + 1];
    s[i + 1] = m[i + 1] = val[i + 1];
  }
  rt = build(1, n + 2);
  cin >> q;
  while (q--) {
    cin >> opt >> x >> y;
    if (x > y)
      swap(x, y);
    splay(x, 0);
    splay(y + 2, x);
    r = spl[y + 2][0];
    if (opt) {
      cout << s[r] << endl;
    } else {
      if (m[r] != 1)
        modify(r);
    }
  }
  return 0;
}