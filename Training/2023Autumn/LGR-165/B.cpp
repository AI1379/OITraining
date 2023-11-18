#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 4095;
ll mp[MAXN][MAXN];
bool used[MAXN][MAXN];
bool vis[MAXN];
ll n;
int main() {
  cin >> n;
  for (int i = n; i >= 1; --i) {
    memset(vis, false, sizeof(vis));
    mp[i][1] = i;
    vis[i] = true;
    for (int j = 2; j <= i; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (!used[k][mp[i][j - 1]] && !vis[k]) {
          mp[i][j] = k;
          used[k][mp[i][j - 1]] = used[mp[i][j - 1]][k] = true;
          vis[k] = true;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cout << mp[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}