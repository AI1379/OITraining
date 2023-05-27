#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n;
vector<ll> tree[MAXN];
ll dp[MAXN];
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  return 0;
}