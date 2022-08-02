#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const ll MAXN = 10010;
struct ScanLine {
  ll pos, lower, upper, val;
};
struct SegtNode {
  ll beg, end, val, tag;
};
ll t;
ll n, w, h;
ll l[MAXN];
SegtNode segt[MAXN * 4];
ScanLine stars[MAXN * 2];
ll tmp[MAXN * 2];
void buildSegt(ll curr, ll l, ll r) {
  segt[curr].beg = l;
  segt[curr].end = r;
  segt[curr].tag = 0;
  segt[curr].val = 0;
  buildSegt(curr * 2, l, (l + r) / 2);
  buildSegt(curr * 2 + 1, (l + r) / 2 + 1, r);
}
void pushUp(ll curr) {
  segt[curr].val = max(segt[curr * 2].val, segt[curr * 2 + 1].val);
}
void pushDown(ll curr) {
  segt[curr * 2].val += segt[curr].tag;
  segt[curr * 2 + 1].val += segt[curr].tag;
  segt[curr * 2].tag += segt[curr].tag;
  segt[curr * 2 + 1].tag += segt[curr].tag;
  segt[curr].tag = 0;
}
void modify(ll curr, ll l, ll r, ll delta) {
  if (l <= segt[curr].beg && segt[curr].end <= r) {
    segt[curr].val += delta;
    segt[curr].tag += delta;
    return;
  }
}
void solve() {
  ll x, y;
  cin >> n >> w >> h;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> l[i];
    stars[i] = (ScanLine) {
      x, y, y + h - 1, l[i]
    };
    stars[i + n] = (ScanLine) {
      x + w - 1, y, y + h - 1, -l[i]
    };
    tmp[i] = y;
    tmp[i + n] = y + h - 1;
  }
  sort(tmp + 1, tmp + n + 1);
  sort(stars + 1, stars + n + 1, [](const ScanLine & lhs, const ScanLine & rhs)->bool {
    if (lhs.pos == rhs.pos)return lhs.val > rhs.val;
    return lhs.pos < rhs.pos;
  });
  ll tot = unique(tmp + 1, tmp + n + 1) - tmp - 1;
  for (int i = 1; i <= 2 * n; i++) {
    stars[i].lower = lower_bound(tmp + 1, tmp + tot + 1, stars[i].lower) - tmp;
    stars[i].upper = lower_bound(tmp + 1, tmp + tot + 1, stars[i].upper) - tmp;
  }
  buildSegt(1, 1, tot);
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
