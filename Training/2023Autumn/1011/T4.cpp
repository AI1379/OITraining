#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, k;
struct Node {
  ll l, r, val, mx;
};
Node segt[MAXN * 4];
struct Patient {
  ll p, t, a, b;
};
Patient pat[MAXN];
void pushup(ll p) { segt[p].mx = min(segt[p * 2].mx, segt[p * 2 + 1].mx); }
void build(ll cur, ll l, ll r) {
  segt[cur].l = l;
  segt[cur].r = r;
  if (l == r) {
    segt[cur].val = segt[cur].mx = pat[l].p;
    return;
  }
  ll mid = (l + r) / 2;
  build(cur * 2, l, mid);
  build(cur * 2 + 1, mid + 1, r);
}
void modify(ll cur, ll p, ll x) {
  if (segt[cur].l == p && segt[cur].r == p) {
    segt[cur].val = segt[cur].mx = x;
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (p <= mid)
    modify(cur * 2, p, x);
  else
    modify(cur * 2 + 1, p, x);
}
ll query(ll cur, ll l, ll r) {
  if (l <= segt[cur].l && segt[cur].r <= r) {
    return segt[cur].mx;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  ll res = 1e9;
  if (l <= mid)
    res = min(res, query(cur * 2, l, r));
  if (mid + 1 <= r)
    res = min(res, query(cur * 2 + 1, l, r));
  return res;
}
struct cmp {
  bool operator()(Patient lhs, Patient rhs) { return lhs.p > rhs.p; }
};
priority_queue<Patient, vector<Patient>, cmp> q;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> pat[i].p;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> pat[i].t;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> pat[i].a;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> pat[i].b;
  }
  sort(pat + 1, pat + n + 1, [](Patient lhs, Patient rhs) {
    return lhs.t == rhs.t ? lhs.p < rhs.p : lhs.t < rhs.t;
  });
  build(1, 1, n);
  ll cur = pat[1].t, ans = 0;
  for (int i = 1; i <= n; ++i) {
    cur = pat[i].t;
    cout << "cur " << cur << ' ' << q.size() << ' '
         << query(1, pat[i].t, pat[i].t + pat[i].b - 1) << endl;
    if (cur > k)
      break;
    if (query(1, pat[i].t, pat[i].t + pat[i].b - 1) < pat[i].p) {
      q.push(pat[i]);
      continue;
    }
    cout << pat[i].p << endl;
    ans += pat[i].a;
    cur = pat[i].t + pat[i].b;
    while (cur <= k && !q.empty()) {
      auto top = q.top();
      cout << "cur " << cur << endl;
      if (query(1, cur, cur + top.b - 1) > top.p) {
        cout << top.p << endl;
        ans += top.a;
        q.pop();
        cur += top.b;
      } else {
        break;
      }
    }
  }
  while (cur <= k && !q.empty()) {
    auto top = q.top();
    cout << "cur " << cur << endl;
    if (query(1, cur, cur + top.b - 1) > top.p) {
      cout << top.p << endl;
      ans += top.a;
      q.pop();
      cur += top.b;
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}