#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define ll long long
const ll MAXN = 510;
const ll MAXM = 200010;
ll n, m, t;
ll a[MAXN], b[MAXN];
struct cmp {
  bool operator()(pair<ll, ll> a, pair<ll, ll> b) { return a.first > b.first; }
};
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> q;
ll cnt = 0, num[MAXN];
ll ans = 0;
int main() {
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    q.push(make_pair(a[i], i));
  }
  pair<ll, ll> tmp;
  ll pos;
  for (int i = 1; i <= m; i++) {
    tmp = q.top();
    q.pop();
    ans += tmp.first;
    pos = tmp.second;
    if (!num[pos]) {
      cnt++;
    }
    num[pos]++;
    q.push(make_pair(a[pos] + b[pos] * num[pos] * num[pos], pos));
  }
  cout << ans + t * (cnt - 1) << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}