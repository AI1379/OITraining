#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
struct Node {
  ll u, v, w;
};
ll n;
ll root;
Node tree[MAXN];
bool fa[MAXN];
bool dfs(ll p, ll q) {
  if (p == 0 && q == 0)
    return true;
  return tree[p].w == tree[q].w && dfs(tree[p].u, tree[q].v) &&
         dfs(tree[p].v, tree[q].u);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> tree[i].u >> tree[i].v >> tree[i].w;
    fa[tree[i].u] = fa[tree[i].v] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (!fa[i]) {
      root = i;
      break;
    }
  }
  if (dfs(root, root)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}

/*
5
2 3 1
0 4 2
5 0 2
0 0 2
0 0 2
*/