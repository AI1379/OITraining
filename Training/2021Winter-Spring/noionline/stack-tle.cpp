#include <iostream>
#include <stack>
using namespace std;
#define ll long long
#ifdef DEBUG
#undef DEBUG
#endif
const ll MAXN = 500010;
ll n, q;
ll a[MAXN], b[MAXN];
ll stk[MAXN], top;
bool check(ll x) {
  ll h;
#ifdef DEBUG
  cout << x << endl;
  cout << "a[x]: " << a[x] << ' ' << b[x] << endl;
#endif
  while (top) {
#ifdef DEBUG
    cout << "top: " << top << endl;
#endif
    h = stk[top];
#ifdef DEBUG
    cout << "a[h]: " << a[h] << ' ' << b[h] << endl;
#endif
    if (a[h] != a[x] && b[h] > b[x]) {
      stk[++top] = x;
#ifdef DEBUG
      cout << "False" << endl;
#endif
      return false;
    }
    top--;
  }
  stk[++top] = x;
#ifdef DEBUG
  cout << "True" << endl;
#endif
  return true;
}
int main() {
  ll l, r, ans;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  while (q--) {
    cin >> l >> r;
    ans = 0;
    top = 0;
    for (int i = l; i <= r; i++) {
      if (check(i)) {
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