#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 25010;
const ll MAXB = 70000;
ll s, t;
ll n, x, y;
ll b[MAXN];
ll bucket[MAXB];
ll last[MAXB];
bool ans[MAXN];
char op[MAXN];
ll highest = 0;
void solve() {
  highest = 0;
  memset(ans, false, sizeof(ans));
  memset(last, 0, sizeof(last));
  memset(b, 0, sizeof(b));
  memset(bucket, 0, sizeof(bucket));
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    highest = max(highest, b[i]);
    ++bucket[b[i]];
    last[b[i]] = i;
    op[i] = '^';
    ans[b[i]] = true;
  }
  for (int i = highest; i >= 0; i--) {
    if (bucket[i] % 2 == 0 && bucket[i] != 0) {
      if (y) {
        op[last[i]] = '|';
        --y;
      } else {
        ans[i] = false;
      }
    }
  }
  for (int i = highest; i >= 0 && y > 0; i--) {
    if (bucket[i] != 0 && op[last[i]] != '|' && last[i] != 1) {
      op[last[i]] = '|';
      --y;
    }
  }
  ll idx = 2;
  while (y > 0) {
    if (op[idx] == '^') {
      op[idx] = '|';
      --y;
    }
    ++idx;
  }
  idx = highest;
  while (!ans[idx] && idx >= 0)
    --idx;
  if (idx < 0) {
    cout << '0';
  }
  for (; idx >= 0; idx--) {
    if (ans[idx]) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << endl;
  for (int i = 2; i <= n; i++) {
    cout << op[i];
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> s >> t;
  while (t--) {
    solve();
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}