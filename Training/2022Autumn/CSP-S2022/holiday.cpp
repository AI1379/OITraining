#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 2510;
ll n, m, k;
ll score[MAXN];
vector<ll> graph[MAXN], lst[MAXN], joi[MAXN];
bool vis[MAXN], check[MAXN][MAXN];
ll ans = 0;
bool cmp(ll lhs, ll rhs) { return score[lhs] > score[rhs]; }
int main() {
  ll u, v;
  cin >> n >> m >> k;
  for (int i = 2; i <= n; ++i)
    cin >> score[i];
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  queue<pll> q;
  pll tmp;
  for (u = 1; u <= n; ++u) {
    memset(vis, false, sizeof(vis));
    q.emplace(u, -1);
    vis[u] = true;
    while (!q.empty()) {
      tmp = q.front();
      q.pop();
      if (tmp.second > k)
        break;
      if (tmp.second >= 0)
        lst[u].emplace_back(tmp.first);
      for (auto k : graph[tmp.first]) {
        if (!vis[k]) {
          vis[k] = true;
          q.emplace(k, tmp.second + 1);
        }
      }
    }
    while (!q.empty())
      q.pop();
  }
  for (int i = 1; i <= n; ++i) {
    for (auto x : lst[i]) {
      check[i][x] = true;
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (auto x : lst[i]) {
      if (check[1][x])
        joi[i].emplace_back(x);
    }
    sort(joi[i].begin(), joi[i].end(), cmp);
  }
  for (int b = 2; b <= n; ++b) {
    for (int c = b + 1; c <= n; ++c) {
      if (!check[b][c] || joi[b].size() == 0 || joi[c].size() == 0)
        continue;
      u = v = 0;
      if (joi[b][u] == c)
        ++u;
      if (u >= (ll)joi[b].size() || v >= (ll)joi[c].size())
        continue;
      if (joi[c][v] == b)
        ++v;
      if (u >= (ll)joi[b].size() || v >= (ll)joi[c].size())
        continue;
      if (joi[b][u] == joi[c][v]) {
        if (u + 1 < (ll)joi[b].size() && v + 1 < (ll)joi[c].size()) {
          if (score[joi[b][u + 1]] > score[joi[c][v + 1]])
            ++u;
          else
            ++v;
        } else if (u + 1 < (ll)joi[b].size()) {
          ++u;
        } else if (v + 1 < (ll)joi[c].size()) {
          ++v;
        } else {
          continue;
        }
      }
      if (u >= (ll)joi[b].size() || v >= (ll)joi[c].size())
        continue;
      if (joi[b][u] == c)
        ++u;
      if (u >= (ll)joi[b].size() || v >= (ll)joi[c].size())
        continue;
      if (joi[c][v] == b)
        ++v;
      if (u >= (ll)joi[b].size() || v >= (ll)joi[c].size())
        continue;
      if (joi[b][u] == joi[c][v]) {
        if (u + 1 < (ll)joi[b].size() && v + 1 < (ll)joi[c].size()) {
          if (score[joi[b][u + 1]] > score[joi[c][v + 1]])
            ++u;
          else
            ++v;
        } else if (u + 1 < (ll)joi[b].size()) {
          ++u;
        } else if (v + 1 < (ll)joi[c].size()) {
          ++v;
        } else {
          continue;
        }
      }
      if (u >= (ll)joi[b].size() || v >= (ll)joi[c].size())
        continue;
      ans = max(ans, score[joi[b][u]] + score[joi[c][v]] + score[b] + score[c]);
    }
  }
  cout << ans << endl;
  return 0;
}