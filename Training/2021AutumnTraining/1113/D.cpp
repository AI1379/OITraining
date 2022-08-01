#include <bits/stdc++.h>
using namespace std;
int stick[100];
bool vis[100];
int len, total, n, group;
inline bool cmp(const int &a, const int &b) { return a > b; }
bool dfs(int complete, int now, int done) {
  if (complete > group) return true;
  if (now == len) return dfs(complete + 1, 0, 1);
  int fail = 0;
  for (int i = done; i <= n; i++) {
    if (!vis[i] && now + stick[i] <= len && fail != stick[i]) {
      vis[i] = true;
      if (dfs(complete, now + stick[i], i + 1)) return true;
      vis[i] = false;
      fail = stick[i];
      if (now == 0 || now + stick[i] == len) return false;
    }
  }
  return false;
}
void solve() {
  sort(stick + 1, stick + n + 1, cmp);
  for (int i = 1; i <= n; i++) total += stick[i];
  for (len = stick[1]; len <= total; len++) {
    if (total % len != 0) continue;
    group = total / len;
    memset(vis, 0, sizeof(vis));
    if (dfs(1, 0, 1)) {
      cout << len << endl;
      return;
    }
  }
  return;
}
int main() {
  while (cin >> n) {
    total = len = 0;
    memset(stick, 0, sizeof(stick));
    for (int i = 1; i <= n; i++) cin >> stick[i];
    if (n == 0) break;
    solve();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}