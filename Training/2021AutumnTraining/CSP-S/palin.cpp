#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int t;
int n;
int a[MAXN * 2];
deque<int> dq;
bool vis[MAXN * 2];
char ans[MAXN * 2];
void solve() {
  memset(vis, false, sizeof(vis));
  dq = deque<int>();
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
    dq.push_back(a[i]);
  }
  vis[dq.front()] = true;
  dq.pop_front();
  for (int i = 2; i <= 2 * n; i++) {
      
  }
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}