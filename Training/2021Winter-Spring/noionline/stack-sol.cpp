#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;
#define ll long long
const ll MAXN = 500010;
struct req {
  ll x, pos, flag, p;
};
ll n, q;
ll a[MAXN], b[MAXN];
ll p[MAXN];
ll bit[MAXN];
stack<ll> stk;
ll lowbit(ll x) { return x & (-x); }
void add(ll x) {
  for (int i = x; i <= n; i += lowbit(i))
    bit[i]++;
}
ll query(ll x) {
  ll res = 0;
  for (int i = x; i; i -= lowbit(i))
    res += bit[i];
  return res;
}
req que[MAXN * 2];
ll ans[MAXN];
int main() {
#ifndef DEBUG
  ios::sync_with_stdio(false);
#endif
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  ll h;
  for (int i = n; i >= 1; i--) {
    while (!stk.empty()) {
      h = stk.top();
      if (a[h] != a[i] && b[h] < b[i]) {
        stk.pop();
        p[h] = i + 1;
      } else {
        break;
      }
    }
    stk.push(i);
  }
  while (!stk.empty()) {
    p[stk.top()] = 1;
    stk.pop();
  }
  for (int i = 1; i <= q; i++) {
    cin >> que[i].x >> que[q + i].x;
    que[i].pos = que[q + i].pos = i;
    que[i].flag = -1;
    que[q + i].flag = 1;
    que[i].p = que[q + i].p = p[que[i].x];
    que[i].x--;
  }
  sort(que + 1, que + q * 2 + 1,
       [](req x, req y) -> bool { return x.x < y.x; });
  ll res, idx = 1;
  while (que[idx].x == 0)
    idx++;
  for (int i = 1; i <= n; i++) {
    add(p[i]);
    while (que[idx].x == i && idx <= q * 2) {
      res = query(que[idx].p);
      ans[que[idx].pos] += (que[idx].flag * res);
      idx++;
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}