// 给定一个由小写字母组成的字符串s。有n次操作，每次操作给3个参数l,r,x。如x=1，将[l,r]升序排序
// 如果x=0，将[l,r]降序排序。你需要求出最终序列。
// http://noip.ybtoj.com.cn/contest/669/problem/5
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pll pair<ll, ll>
const ll MAXN = 100010;
struct Node {
  ll l, r;
  ll val;
  ll s, t;
  bool tag;
};
ll n, m;
char str[MAXN];
ll root;
Node segt[26][MAXN * 4];
void pushup(ll c, ll p) {
  segt[c][p].val = segt[c][p * 2].val + segt[c][p * 2 + 1].val;
}
void pushdown(ll c, ll p) {
  if (segt[c][p].tag) {
#ifdef DEBUG
    // cout << "Pushing down " << (char)(c + 'a') << ' ' << segt[c][p].l << ' '
    //  << segt[c][p].r << endl;
#endif
    segt[c][p * 2].s = max(segt[c][p * 2].l, segt[c][p].s);
    segt[c][p * 2].t = min(segt[c][p * 2].r, segt[c][p].t);
    segt[c][p * 2].val = max(0, segt[c][p * 2].t - segt[c][p * 2].s + 1);
    segt[c][p * 2 + 1].s = max(segt[c][p * 2 + 1].l, segt[c][p].s);
    segt[c][p * 2 + 1].t = min(segt[c][p * 2 + 1].r, segt[c][p].t);
    segt[c][p * 2 + 1].val =
        max(0, segt[c][p * 2 + 1].t - segt[c][p * 2 + 1].s + 1);
    segt[c][p].tag = false;
    segt[c][p * 2].tag = segt[c][p * 2 + 1].tag = true;
  }
}
void build(ll c, ll p, ll l, ll r) {
  segt[c][p].l = l;
  segt[c][p].r = r;
  if (l == r) {
    segt[c][p].val = (str[l] == 'a' + c ? 1 : 0);
    return;
  }
  ll mid = (l + r) >> 1;
  build(c, p * 2, l, mid);
  build(c, p * 2 + 1, mid + 1, r);
  pushup(c, p);
}
ll querySegt(ll c, ll p, ll l, ll r) {
  if (l <= segt[c][p].l && segt[c][p].r <= r)
    return segt[c][p].val;
  ll mid = ((segt[c][p].l + segt[c][p].r) >> 1), res = 0;
  pushdown(c, p);
  if (l <= mid)
    res += querySegt(c, p * 2, l, r);
  if (mid + 1 <= r)
    res += querySegt(c, p * 2 + 1, l, r);
  return res;
}
void modifySegt(ll c, ll p, ll l, ll r, ll s, ll t) {
  if (l <= segt[c][p].l && segt[c][p].r <= r) {
    segt[c][p].val = max(0, t - s + 1);
    segt[c][p].s = s;
    segt[c][p].t = t;
    segt[c][p].tag = true;
    return;
  }
  ll mid = (segt[c][p].l + segt[c][p].r) >> 1;
  pushdown(c, p);
  if (l <= mid)
    modifySegt(c, p * 2, l, r, max(segt[c][p].l, s), min(mid, t));
  if (mid + 1 <= r)
    modifySegt(c, p * 2 + 1, l, r, max(mid + 1, s), min(segt[c][p].r, t));
  pushup(c, p);
}
void modify(ll l, ll r, ll x) {
  ll t = 0, k;
  if (x == 1) {
    for (int c = 0; c < 26; ++c) {
      k = querySegt(c, 1, l, r);
      modifySegt(c, 1, l, r, t + l, t + l + k - 1);
      t += k;
#ifdef DEBUG
      cout << t << endl;
#endif
    }
  } else {
    for (int c = 25; c >= 0; --c) {
      k = querySegt(c, 1, l, r);
      modifySegt(c, 1, l, r, t + l, t + l + k - 1);
      t += k;
#ifdef DEBUG
      cout << t << endl;
#endif
    }
  }
}
ll l, r, x;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", str + 1);
  for (int c = 0; c < 26; ++c)
    build(c, 1, 1, n);
  while (m--) {
    scanf("%d%d%d", &l, &r, &x);
    modify(l, r, x);
  }
  for (int i = 1; i <= n; ++i) {
    for (int c = 0; c < 26; ++c) {
      if (querySegt(c, 1, i, i) == 1) {
        printf("%c", c + 'a');
      }
    }
  }
  printf("\n");
  return 0;
}