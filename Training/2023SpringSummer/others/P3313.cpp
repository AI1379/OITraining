#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
struct Node {
  ll l, r;
  ll lson, rson;
  ll s, m;
};
ll n, q;
ll tot, root[MAXN];
Node segt[MAXN * 20];
vector<ll> tree[MAXN];
ll tag[MAXN], val[MAXN];
ll idx, weight[MAXN], prefer[MAXN];
ll dfn[MAXN], f[MAXN], top[MAXN], dep[MAXN];
void getson(ll u, ll fa) {
  weight[u] = 1;
  f[u] = fa;
  dep[u] = dep[fa] + 1;
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    getson(v, u);
    weight[u] += weight[v];
    if (weight[prefer[u]] < weight[v])
      prefer[u] = v;
  }
}
void decomposition(ll u, ll t) {
  dfn[u] = ++idx;
  top[u] = t;
  if (prefer[u])
    decomposition(prefer[u], t);
  for (auto v : tree[u]) {
    if (v == f[u] || v == prefer[u])
      continue;
    decomposition(v, v);
  }
}
ll newnode(ll l, ll r) {
  ++tot;
  segt[tot].l = l;
  segt[tot].r = r;
  return tot;
}
void pushup(ll cur) {
  segt[cur].m = max(segt[segt[cur].lson].m, segt[segt[cur].rson].m);
  segt[cur].s = segt[segt[cur].lson].s + segt[segt[cur].rson].s;
}
void modify(ll s, ll v, ll cur) {
  if (segt[cur].l == s && segt[cur].r == s) {
    segt[cur].m = segt[cur].s = v;
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (s <= mid) {
    if (!segt[cur].lson)
      segt[cur].lson = newnode(segt[cur].l, mid);
    modify(s, v, segt[cur].lson);
  } else {
    if (!segt[cur].rson)
      segt[cur].rson = newnode(mid + 1, segt[cur].r);
    modify(s, v, segt[cur].rson);
  }
  pushup(cur);
}
ll querymx(ll s, ll t, ll cur) {
  if (s > t)
    swap(s, t);
  if (s <= segt[cur].l && segt[cur].r <= t)
    return segt[cur].m;
  ll mid = (segt[cur].l + segt[cur].r) / 2, res = 0;
  if (s <= mid && segt[cur].lson)
    res = max(res, querymx(s, t, segt[cur].lson));
  if (mid + 1 <= t && segt[cur].rson)
    res = max(res, querymx(s, t, segt[cur].rson));
  return res;
}
ll querysum(ll s, ll t, ll cur) {
  if (s > t)
    swap(s, t);
  if (s <= segt[cur].l && segt[cur].r <= t)
    return segt[cur].s;
  ll mid = (segt[cur].l + segt[cur].r) / 2, res = 0;
  if (s <= mid && segt[cur].lson)
    res += querysum(s, t, segt[cur].lson);
  if (mid + 1 <= t && segt[cur].rson)
    res += querysum(s, t, segt[cur].rson);
  return res;
}
void modifyc(ll p, ll c) {
  modify(dfn[p], 0, root[tag[p]]);
  tag[p] = c;
  modify(dfn[p], val[p], root[c]);
}
void modifyw(ll p, ll w) {
  modify(dfn[p], w, root[tag[p]]);
  val[p] = w;
}
ll querys(ll u, ll v) {
  ll res = 0, c = tag[u];
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    res += querysum(dfn[u], dfn[top[u]], root[c]);
    u = f[top[u]];
  }
  res += querysum(dfn[u], dfn[v], root[c]);
  return res;
}
ll querym(ll u, ll v) {
  ll res = 0, c = tag[u];
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    res = max(res, querymx(dfn[u], dfn[top[u]], root[c]));
    u = f[top[u]];
  }
  res = max(res, querymx(dfn[u], dfn[v], root[c]));
  return res;
}
int main() {
  ll u, v;
  string op;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i] >> tag[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  getson(1, 0);
  decomposition(1, 1);
  for (int i = 1; i <= n; ++i) {
    if (!root[tag[i]])
      root[tag[i]] = newnode(1, idx);
    modify(dfn[i], val[i], root[tag[i]]);
  }
  while (q--) {
    cin >> op >> u >> v;
    if (op == "CC") {
      modifyc(u, v);
    } else if (op == "CW") {
      modifyw(u, v);
    } else if (op == "QS") {
      cout << querys(u, v) << endl;
    } else if (op == "QM") {
      cout << querym(u, v) << endl;
    }
  }
  return 0;
}