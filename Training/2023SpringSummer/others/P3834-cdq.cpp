#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 200010;
const ll MAXM = 200010;
struct Query {
  ll l, r, k, idx;
};
static ll n, m, num;
static Query q[MAXM];
static ll f[MAXN];
static pll val[MAXN];
static ll bit[MAXN];
static ll curtag = 0;
static ll tag[MAXN];
static ll ans[MAXM];
ll lowbit(ll x) { return x & (-x); }
void modify(ll v, ll d) {
  for (; v <= n; v += lowbit(v)) {
    if (tag[v] != curtag) {
      tag[v] = curtag;
      bit[v] = 0;
    }
    bit[v] += d;
  }
}
ll query(ll p) {
  ll res = 0;
  for (; p; p -= lowbit(p)) {
    if (tag[p] != curtag) {
      tag[p] = curtag;
      bit[p] = 0;
    }
    res += bit[p];
  }
  return res;
}

static Query q1[MAXN], q2[MAXN];
static pll v1[MAXN], v2[MAXN];

void solve(ll l, ll r, ll vl, ll vr, ll ql, ll qr) {
  if (l == r) {
    for (int i = ql; i <= qr; ++i) {
      ans[q[i].idx] = f[l];
    }
    return;
  }
  ll mid = (l + r) / 2;
  ll vcnt1 = 0, vcnt2 = 0;
  for (int i = vl; i <= vr; ++i) {
    if (val[i].first <= mid) {
      v1[++vcnt1] = val[i];
      modify(val[i].second, 1);
    } else {
      v2[++vcnt2] = val[i];
    }
  }
  ll qcnt1 = 0, qcnt2 = 0;
  for (int i = ql; i <= qr; ++i) {
    auto t = query(q[i].r) - query(q[i].l - 1);
    if (q[i].k <= t) {
      q1[++qcnt1] = q[i];
    } else {
      q[i].k -= t;
      q2[++qcnt2] = q[i];
    }
  }
  ++curtag;
  for (int i = vl; i <= vl + vcnt1 - 1; ++i)
    val[i] = v1[i - vl + 1];
  for (int i = vl + vcnt1; i <= vr; ++i)
    val[i] = v2[i - vl - vcnt1 + 1];
  for (int i = ql; i <= ql + qcnt1 - 1; ++i)
    q[i] = q1[i - ql + 1];
  for (int i = ql + qcnt1; i <= qr; ++i)
    q[i] = q2[i - ql - qcnt1 + 1];
  solve(l, mid, vl, vl + vcnt1 - 1, ql, ql + qcnt1 - 1);
  solve(mid + 1, r, vl + vcnt1, vr, ql + qcnt1, qr);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i].first;
    f[i] = val[i].first;
    val[i].second = i;
  }
  sort(f + 1, f + n + 1);
  num = unique(f + 1, f + n + 1) - f - 1;
  for (int i = 1; i <= n; ++i) {
    val[i].first = lower_bound(f + 1, f + num + 1, val[i].first) - f;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].l >> q[i].r >> q[i].k;
    q[i].idx = i;
  }
  solve(1, num, 1, n, 1, m);
  for (int i = 1; i <= m; ++i)
    cout << ans[i] << endl;
  return 0;
}