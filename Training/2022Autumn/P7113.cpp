#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll MAXN = 100010;
template <typename T>
struct Fraction {
  T p, q;
};
typedef Fraction<ll> frac;
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd<T>(b, a % b);
}
template <typename T>
void simplify(Fraction<T> &x) {
  T g;
  g = gcd<T>(x.p, x.q);
  x.p /= g;
  x.q /= g;
}
frac inv(frac x) {
  swap(x.p, x.q);
  return x;
}
frac operator-(frac x) {
  x.p = -x.p;
  return x;
}
frac operator+(const frac &lhs, const frac &rhs) {
  static frac res;
  res.q = lhs.q * rhs.q / gcd(lhs.q, rhs.q);
  res.p = lhs.p * (res.q / lhs.q) + rhs.p * (res.q / rhs.q);
  simplify(res);
  return res;
}
frac operator-(const frac &lhs, const frac &rhs) { return lhs + (-rhs); }
frac operator*(const frac &lhs, const frac &rhs) {
  static frac res;
  res.p = lhs.p * rhs.p;
  res.q = lhs.q * rhs.q;
  simplify(res);
  return res;
}
frac operator/(const frac &lhs, const frac &rhs) { return lhs * inv(rhs); }
frac operator/(frac lhs, const ll &rhs) {
  lhs.q *= rhs;
  simplify(lhs);
  return lhs;
}
ostream &operator<<(ostream &os, const frac &x) {
  os << x.p << ' ' << x.q;
  return os;
}
ll n, m;
vector<ll> graph[MAXN];
ll deg[MAXN];
frac val[MAXN];
queue<ll> q;
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    val[i] = {0, 1};
    cin >> u;
    for (int j = 1; j <= u; ++j) {
      cin >> v;
      graph[i].emplace_back(v);
      ++deg[v];
    }
    if (i <= m) {
      q.push(i);
      val[i] = {1, 1};
    }
  }
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto v : graph[u]) {
      val[v] = val[v] + (val[u] / graph[u].size());
      --deg[v];
      if (deg[v] == 0) q.push(v);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (graph[i].size() == 0) cout << val[i] << endl;
  }
  return 0;
}