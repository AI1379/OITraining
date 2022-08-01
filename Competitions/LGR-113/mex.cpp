#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n;
ll a[MAXN], b[MAXN];
ll pos[MAXN], len[MAXN];
ll ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      len[a[i]] = max(len[a[i]], i - pos[a[i]] - 1);
      pos[a[i]] = i;
    }
  }
  for (int x = 0; x <= n; x++) {
    len[x] = max(len[x], n - pos[x]);
  }
  for (int x = 0; x <= n; x++) {
    ans = max(ans, len[x] - x);
  }
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}