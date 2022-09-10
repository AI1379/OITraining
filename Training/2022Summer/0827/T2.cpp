#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
ll n, m;
vector<pll> graph[MAXN];
ll k, x, y;
ll t;
ll cnt;
ll deg[MAXN];
queue<ll> jq;
bool judge(ll s) {
  cnt = 0;
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i <= n; i++) {
    for (pll &obj : graph[i]) {
      if (obj.second > s)
        continue;
      ++deg[obj.first];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) {
      jq.push(i);
      ++cnt;
    }
  }
  while (!jq.empty()) {
    y = jq.front();
    jq.pop();
    for (pll &obj : graph[y]) {
      if (obj.second > s)
        continue;
      --deg[obj.first];
      if (!deg[obj.first]) {
        jq.push(obj.first);
        ++cnt;
      }
    }
  }
  return cnt == n;
}
priority_queue<ll, vector<ll>, greater<ll>> q;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> k;
    cin >> x;
    for (int j = 2; j <= k; ++j) {
      cin >> y;
      graph[x].push_back(make_pair(y, i));
      x = y;
    }
  }
  ll l = 1, r = m, mid;
  x = 1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (judge(mid)) {
      x = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i <= n; i++) {
    for (pll &obj : graph[i]) {
      if (obj.second > x)
        continue;
      ++deg[obj.first];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!deg[i])
      q.push(i);
  }
#ifdef DEBUG
  cout << x << '\n';
#endif
  while (!q.empty()) {
    t = q.top();
    q.pop();
    cout << t << ' ';
    for (pll &obj : graph[t]) {
      if (obj.second > x)
        continue;
      --deg[obj.first];
      if (!deg[obj.first])
        q.push(obj.first);
    }
  }
  cout << '\n';
  return 0;
}