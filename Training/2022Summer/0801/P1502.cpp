#include <algorithm>
#include <cstring>
#include <iostream>


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
  if (l == r) {
    return;
  }
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
  ll mid = (segt[curr].beg + segt[curr].end) / 2;
  pushDown(curr);
  if (l <= mid) {
    modify(curr * 2, l, r, delta);
  }
  if (mid < r) {
    modify(curr * 2 + 1, l, r, delta);
  }
  pushUp(curr);
}
void solve() {
  ll x, y;
  ll ans = 0;
  memset(segt, 0, sizeof(segt));
  memset(stars, 0, sizeof(stars));
  cin >> n >> w >> h;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> l[i];
    stars[i] = (ScanLine){x, y, y + h - 1, l[i]};
    stars[i + n] = (ScanLine){x + w - 1, y, y + h - 1, -l[i]};
    tmp[i] = y;
    tmp[i + n] = y + h - 1;
  }
  sort(tmp + 1, tmp + n + 1);
  sort(stars + 1, stars + n + 1,
       [](const ScanLine &lhs, const ScanLine &rhs) -> bool {
         if (lhs.pos == rhs.pos)
           return lhs.val > rhs.val;
         return lhs.pos < rhs.pos;
       });
  ll tot = unique(tmp + 1, tmp + 2 * n + 1) - tmp - 1;
  for (int i = 1; i <= 2 * n; i++) {
    stars[i].lower = lower_bound(tmp + 1, tmp + tot + 1, stars[i].lower) - tmp;
    stars[i].upper = lower_bound(tmp + 1, tmp + tot + 1, stars[i].upper) - tmp;
  }
  buildSegt(1, 1, tot);
  for (int i = 1; i <= 2 * n; i++) {
    modify(1, stars[i].lower, stars[i].upper, stars[i].val);
    ans = max(ans, segt[1].val);
  }
  cout << ans << endl;
  return;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
