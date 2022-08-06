#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll MAXN = 100010;
static ll n, m, s;
vector<pll>graph[MAXN];
struct Node {
  ll l, r, val, tag;
};
ll dis[MAXN];
Node segt[MAXN * 4];
void build(ll beg,ll end){
  
}
void modify(ll beg,ll end,ll pos,ll val)
int main() {
  ll u, v, w;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
  }

  return 0;
}
