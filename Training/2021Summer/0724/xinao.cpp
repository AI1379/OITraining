#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int w[200010], v[200010];
node lst[200010];
map<int, int> mp;
int req[200010][2];
int c[2][400010];
int lowbit(int x) { return x & (-x); }
void add(int pos, int num, int tp) {
  int x = pos;
  while (x <= 32010) {
    c[tp][x] += num;
    x += lowbit(x);
  }
}
int query(int pos, int tp) {
  int res = 0;
  while (pos >= 1) {
    res += c[tp][pos];
    pos -= lowbit(pos);
  }
  return res;
}
bool judge(int w1, int w2) {
  if (w1 >= w2) {
    
  }
}
int main() {
  int maxw = 0;
  cin >> n >> m >> s;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    maxw = max(maxw, w[i]);
    if (mp[w[i]] == 0) mp[w[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> req[i][0] >> req[i][1];
  }
  int l = 0, r = maxw;
  int mid, lmid = 0;
  while (l < r) {
    mid = (l + r) / 2;
    if (judge(mid, lmid)) {
    } else {
    }
    lmid = mid;
  }
}