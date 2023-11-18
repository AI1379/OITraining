#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
ll n, m1, m2;
pll in[MAXN], out[MAXN];
ll innum[MAXN], outnum[MAXN];
ll curin, curout;
priority_queue<pll, vector<pll>, greater<pll>> inuse;
priority_queue<ll, vector<ll>, greater<ll>> avail;
int main() {
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= m1; ++i) {
    cin >> in[i].first >> in[i].second;
  }
  for (int i = 1; i <= m2; ++i) {
    cin >> out[i].first >> out[i].second;
  }
  pll tmp;
  sort(in + 1, in + m1 + 1);
  sort(out + 1, out + m2 + 1);
  for (int i = 1; i <= m1; ++i) {
    while (!inuse.empty() && inuse.top().first <= in[i].first) {
      avail.push(inuse.top().second);
      inuse.pop();
    }
    if (avail.empty())
      avail.push(++curin);
    ++innum[avail.top()];
    inuse.push({in[i].second, avail.top()});
    avail.pop();
  }
  while (!inuse.empty())
    inuse.pop();
  while (!avail.empty())
    avail.pop();
  for (int i = 1; i <= m2; ++i) {
    while (!inuse.empty() && inuse.top().first <= out[i].first) {
      avail.push(inuse.top().second);
      inuse.pop();
    }
    if (avail.empty())
      avail.push(++curout);
    ++outnum[avail.top()];
    inuse.push({out[i].second, avail.top()});
    avail.pop();
  }
  for (int i = 1; i <= n; ++i) {
    innum[i] += innum[i - 1];
    outnum[i] += outnum[i - 1];
  }
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, innum[i] + outnum[n - i]);
  }
  cout << ans << endl;
  return 0;
}
/**
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
**/