#include <iostream>
#include <stack>
using namespace std;
#define ll long long
const ll MAXN = 500010;
ll n, q;
ll a[MAXN], b[MAXN];
ll stk[MAXN], top;
ll p[MAXN];
int main() {
#ifndef DEBUG
#ifndef VSCODE
  freopen("stack2.in", "r", stdin);
  // freopen("stack.out", "w", stdout);
#endif
#endif
  ll l, r, ans;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  ll h;
  for (int i = 1; i <= n; i++) {
    while (top) {
      h = stk[top];
      if (a[h] != a[i] && b[h] > b[i]) {
        break;
      }
      top--;
    }
    p[i] = stk[top];
    stk[++top] = i;
  }
  while (q--) {
    cin >> l >> r;
    ans = 0;
    for (int i = l; i <= r; i++) {
      if (p[i] <= l) {
        ans++;
      }
    }
    cout << ans << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}