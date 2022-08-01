#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MAXK = 10;
const ll MOD = 1000000007;
ll t, n, k;
ll mp[MAXK][MAXK];
vector<ll> tree[MAXN];
ll ans = 0;
void dfs()
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      cin >> mp[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    tree[i].clear();
  }

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