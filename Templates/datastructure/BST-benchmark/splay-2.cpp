#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, m;
ll rt;
ll child[MAXN][2];
ll pa[MAXN];
ll siz[MAXN], sum[MAXN], val[MAXN], tag[MAXN];
ll which(ll x) { return child[pa[x]][1] == x; }
void pushup(ll x) {
  siz[x] = siz[child[x][0]] + siz[child[x][1]] + 1;
  sum[x] = sum[child[x][0]] + sum[child[x][1]] + val[x];
}
void modifynode(ll x, ll d) {
  sum[x] += siz[x] * d;
  val[x] += d;
  tag[x] += d;
}
void pushdown(ll x) {
  if (tag[x]) {
    modifynode(child[x][0], tag[x]);
    modifynode(child[x][1], tag[x]);
    tag[x] = 0;
  }
}
void rotate(ll x) {
  auto p = pa[x], gp = pa[p];
  auto chkp = which(p), chkx = which(x);
  pushdown(gp);
  pushdown(p);
  child[p][chkx] = child[x][chkx ^ 1];
  if (child[x][chkx ^ 1])
    pa[child[x][chkx ^ 1]] = p;
  child[x][chkx ^ 1] = p;
  pa[p] = x;
  pa[x] = gp;
  if (gp)
    child[gp][chkp] = x;
  pushup(p);
  pushup(x);
}
int main() { return 0; }