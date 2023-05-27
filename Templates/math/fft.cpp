#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 3000010;
const double pi = acos(-1.0);
ll n, m;
complex<double> a[MAXN], b[MAXN];
void FFT(complex<double> *f, ll n, ll inv) {
  if (n == 1)
    return;
  ll mid = n / 2;
  complex<double> a1[mid + 1], a2[mid + 1];
  complex<double> w0(1, 0), wn(cos(2 * pi / n), inv * sin(2 * pi / n));
  for (ll i = 0; i <= n; i += 2) {
    cout << i / 2 << endl;
    a1[i / 2] = f[i];
    a2[i / 2] = f[i + 1];
  }
  FFT(a1, mid, inv);
  FFT(a2, mid, inv);
  for (ll i = 0; i < mid; ++i, w0 *= wn) {
    f[i] = a1[i] + w0 * a2[i];
    f[i + n / 2] = a1[i] - w0 * a2[i];
  }
}
int main() {
  ll x;
  freopen("P3803_5.in", "r", stdin);
  cin >> n >> m;
  cout << n << " " << m << endl;
  for (ll i = 0; i <= n; ++i) {
    cin >> x;
    a[i].real(x);
  }
  for (ll i = 0; i <= m; ++i) {
    cin >> x;
    b[i].real(x);
  }
  ll len = 1 << max(((ll)(ceil(log2(n + m)))), 1ll);
  FFT(a, len, 1);
  FFT(b, len, 1);
  for (ll i = 0; i <= len; ++i) {
    a[i] = a[i] * b[i];
  }
  FFT(a, len, -1);
  for (ll i = 0; i <= n + m; ++i) {
    cout << (a[i].real() / len) << ' ';
  }
  cout << endl;
  return 0;
}
/*
1 2
1 2
1 2 1

1 4 5 2

*/