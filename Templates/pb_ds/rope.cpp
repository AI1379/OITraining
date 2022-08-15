#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
static ll n, m, x;
static ll v, k, s, t;
__gnu_cxx::rope<ll> *versions[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  versions[0] = new __gnu_cxx::rope<ll>();
  for (int i = 1; i <= n; i++) {
    cin >> x;
    versions[0]->append(x);
  }
  for (int i = 1; i <= m; i++) {
    cin >> v >> k;
    versions[i] = new __gnu_cxx::rope<ll>(*versions[v]);
    if (k == 1) {
      cin >> s >> t;
      versions[i]->replace(s - 1, t);
    } else {
      cin >> x;
      cout << versions[i]->at(x - 1) << endl;
    }
  }
  return 0;
}
