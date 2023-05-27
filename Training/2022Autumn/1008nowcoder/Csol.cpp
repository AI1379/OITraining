#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 300010;
ll n;
ll disjfa[MAXN];
ll disjfind(ll x) {
  return disjfa[x] == x ? x : disjfa[x] = disjfind(disjfa[x]);
}
void merge(ll u, ll v) {
  static ll fu, fv;
  fu = disjfind(u);
  fv = disjfind(v);
  if (fu != fv)
    disjfa[fu] = fv;
}
ll virtnode = 0;
ll a[MAXN];
char ans[MAXN];
set<ll> tree[MAXN];
pair<ll, ll> edges[MAXN];
bool isvirt[MAXN];
int main() {
  ll u, v, w, x, y;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    disjfa[i] = i;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v >> w;
    if (w == 0)
      merge(u, v);
    edges[i] = make_pair(u, v);
  }
  for (int i = 1; i <= n - 1; ++i) {
    tree[disjfind(edges[i].first)].insert(disjfind(edges[i].second));
    tree[disjfind(edges[i].second)].insert(disjfind(edges[i].first));
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = disjfind(a[i]);
  }
  for (int i = n; i >= 1; --i) {
    if (virtnode == 0)
      ans[i] = '1';
    else
      ans[i] = '0';
    u = a[i];
    if (tree[u].size() >= 3) {
      ++virtnode;
      isvirt[u] = true;
    } else {
      for (auto it = tree[u].begin(); it != tree[u].end(); ++it) {
        v = *it;
        cout << v << endl;
        cout << "FF" << endl;
        cout << tree[v].count(u) << endl;
        tree[v].erase(tree[v].find(u));
        if (tree[v].size() == 2 && isvirt[v]) {
          --virtnode;
          x = *(tree[v].begin());
          y = *(tree[v].rbegin());
          cout << "A" << endl;
          tree[x].erase(tree[x].find(v));
          cout << "B" << endl;
          tree[y].erase(tree[y].find(v));
          cout << "C" << endl;
          tree[x].insert(y);
          cout << "D" << endl;
          tree[y].insert(x);
          cout << "E" << endl;
        }
      }
      tree[u] = set<ll>();
    }
  }
  cout << string(ans + 1) << endl;
  return 0;
}