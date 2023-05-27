#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MAXN = 500010;
ll n, m, q;
ull hashsum = 0, sum;
set<ull> valset;
ull val[MAXN], hashdeg[MAXN], curhashdeg[MAXN];
ll degsum, deg[MAXN], curdeg[MAXN];
int main() {
  ll u, v, opt;
  cin >> n >> m;
  std::random_device rd;
  std::mt19937_64 rng(rd());
  std::uniform_int_distribution<ull> dist;
  for (int i = 1; i <= n; ++i) {
    do {
      v = dist(rng);
    } while (valset.find((ull)v) != valset.end());
    val[i] = (ull)v;
    valset.insert((ull)v);
    sum ^= (ull)v;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    hashdeg[v] ^= val[u];
    curhashdeg[v] ^= val[u];
    hashsum ^= val[u];
    ++curdeg[v];
    ++deg[v];
    ++degsum;
  }
  cin >> q;
  while (q--) {
    cin >> opt;
    switch (opt) {
    case 1: {
      cin >> u >> v;
      --curdeg[v];
      --degsum;
      hashsum ^= val[u];
      curhashdeg[v] ^= val[u];
      break;
    }
    case 2: {
      cin >> u;
      hashsum ^= curhashdeg[u];
      degsum -= curdeg[u];
      curdeg[u] = curhashdeg[u] = 0;
      break;
    }
    case 3: {
      cin >> u >> v;
      ++curdeg[v];
      ++degsum;
      hashsum ^= val[u];
      curhashdeg[v] ^= val[u];
      break;
    }
    case 4: {
      cin >> u;
      hashsum ^= (hashdeg[u] ^ curhashdeg[u]);
      degsum += (deg[u] - curdeg[u]);
      curdeg[u] = deg[u];
      curhashdeg[u] = hashdeg[u];
      break;
    }
    }
    if (degsum == n && hashsum == sum) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/