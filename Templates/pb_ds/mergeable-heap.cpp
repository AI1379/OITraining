#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll MAXN = 100010;
ll n, m;
ll fa[MAXN];
bool deleted[MAXN];
__gnu_pbds::priority_queue<pll, greater<pll>> heaps[MAXN];
ll find(ll x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
  ll opt, x, y, fax, fay;
  pll obj;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    deleted[i] = false;
    cin >> x;
    heaps[i].push(make_pair(x, i));
  }
  while (m--) {
    cin >> opt;
    if (opt == 1) {
      cin >> x >> y;
      fax = find(x);
      fay = find(y);
      if (fax == fay || deleted[x] || deleted[y]) {
        continue;
      }
      if (heaps[fax].size() >= heaps[fay].size()) {
        fa[fay] = fax;
        heaps[fax].join(heaps[fay]);
      } else {
        fa[fax] = fay;
        heaps[fay].join(heaps[fax]);
      }
    } else {
      cin >> x;
      if (deleted[x]) {
        cout << "-1" << endl;
        continue;
      }
      fax = find(x);
      obj = heaps[fax].top();
      cout << obj.first << endl;
      deleted[obj.second] = true;
      heaps[fax].pop();
    }
  }
  return 0;
}
