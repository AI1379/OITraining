#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
ll n, m1, m2;
pll in[MAXN], out[MAXN];
int main() {
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= m1; ++i) {
    cin >> in[i].first >> in[i].second;
  }
  for (int i = 1; i <= m2; ++i) {
    cin >> out[i].first >> out[i].second;
  }
  return 0;
}