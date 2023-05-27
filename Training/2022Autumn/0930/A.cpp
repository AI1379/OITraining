// https://www.luogu.com.cn/problem/P5118
#include <bits/stdc++.h>
using namespace std;
#define ll long long
set<ll> res;
ll pos[31], buck[31];
void dfs(ll dep, ll cur) {
  if (dep >= 4) {
    res.insert(cur);
    return;
  }
  for (int i = 1; i <= 20; ++i) {
    if ((dep & 1) == pos[i]) {
      pos[i] ^= 1;
      dfs(dep + 1, cur + buck[i] * (pos[i] == 1 ? -1 : 1));
      pos[i] ^= 1;
    }
  }
}
int main() {
  for (int i = 1; i <= 20; ++i) {
    cin >> buck[i];
    pos[i] = (i - 1) / 10;
  }
  dfs(0, 1000);
  cout << res.size() << endl;
  return 0;
}