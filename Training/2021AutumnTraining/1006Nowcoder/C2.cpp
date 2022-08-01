#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tree tr[t]
int t;
int n;
deque<int> tr[6][100010];
priority_queue<int> dfs(int u, int fa) {
  priority_queue<int> h;
  priority_queue<int> tmp;
  for (int i = 0; i < tree[u].size(); i++) {
    if (tree[u][i] != fa) tmp = dfs(tree[u][i], u);
    while (!tmp.empty()) {
      h.push(tmp.top());
      tmp.pop();
    }
  }
  int x = 0, y = 0;
  if (!h.empty()) {
    x = h.top();
    h.pop();
  }
  if (!h.empty()) {
    y = h.top();
    h.pop();
  }
  h.push(x + y + 1);
  return h;
}
void solve() {
  cin >> n;
  int u, v;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  priority_queue<int> h = dfs(1, 0);
  cout << h.top() << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}