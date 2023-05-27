#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXSQRTN = 100010;
ll n;
ll x, y;
bool vis[MAXSQRTN];
vector<ll> pri;
int main() {
  cin >> n;
  x = 1;
  y = n;
  for (ll i = 2; i <= 100000; ++i) {
    if (!vis[i])
      pri.emplace_back(i);
    for (ll j : pri) {
      if (1ll * i * j >= MAXSQRTN)
        break;
      vis[1ll * i * j] = true;
      if (i % j == 0)
        break;
    }
  }
  for (ll p : pri) {
    if (p * p > y)
      break;
    while (y % (p * p) == 0) {
      y /= (p * p);
      x *= p;
    }
  }
  cout << x << ' ' << y << endl;
  return 0;
}