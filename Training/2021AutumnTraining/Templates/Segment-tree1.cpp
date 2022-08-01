// P3372
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, m;
int a[MAXN];
int f[MAXN * 4];
int lazy[MAXN * 4];
void build(int s, int t, int pos) {
  if (s == t) {
    f[pos] = a[s];
    return;
  }
  int mid = (s + t) / 2;
  build(s, mid, pos * 2);
  build(mid + 1, t, pos * 2 + 1);
  f[pos] = f[pos * 2] + f[pos * 2 + 1];
}
int getsum(int l, int r, int s, int t, int pos) {
  if (l <= s && t <= r) return f[pos];
  int mid = (s + t) / 2, res = 0;
  if (lazy[pos]) {
    f[pos * 2] += (mid - s + 1) * lazy[pos];
    f[pos * 2 + 1] += (t - mid) * lazy[pos];
    lazy[pos * 2] += lazy[pos];
    lazy[pos * 2 + 1] += lazy[pos];
    lazy[pos] = 0;
  }
  if (l <= mid) res += getsum(l, r, s, mid, pos * 2);
  if (mid < r) res += getsum(l, r, mid + 1, t, pos * 2 + 1);
  return res;
}
int getsum(int s, int t) { return getsum(s, t, 1, n, 1); }
int getnum(int x) { return getsum(x, x); }
void modify(int l, int r, int k, int s, int t, int pos) {
  if (l <= s && t <= r) {
    f[pos] += (t - s + 1) * k;
    lazy[pos] = k;
    return;
  }
  int mid = (s + t) / 2;
  if (lazy[pos]) {
    f[pos * 2] += (mid - s + 1) * lazy[pos];
    f[pos * 2 + 1] += (t - mid) * lazy[pos];
    lazy[pos * 2] += lazy[pos];
    lazy[pos * 2 + 1] += lazy[pos];
    lazy[pos] = 0;
  }
  if (l <= mid) modify(l, r, k, s, mid, pos * 2);
  if (mid < r) modify(l, r, k, mid + 1, t, pos * 2 + 1);
  f[pos] = f[pos * 2] + f[pos * 2 + 1];
}
void modify(int s, int t, int k) { modify(s, t, k, 1, n, 1); }

void print() {
  struct node {
    int pos, l, r, dep;
  };
  queue<node> q;
  q.push((node){1, 1, n, 1});
  node x = (node){0, 0, 0, 1};
  int mid;
  while (!q.empty()) {
    if (q.front().dep > x.dep) cout << endl;
    x = q.front();
    q.pop();
    cout << "(" << x.pos << ": " << f[x.pos] << ", [" << x.l << ", " << x.r
         << "], lazy tag: " << lazy[x.pos] << ") ";
    mid = (x.l + x.r) / 2;
    if (x.l == x.r) continue;
    q.push((node){x.pos * 2, x.l, mid, x.dep + 1});
    q.push((node){x.pos * 2 + 1, mid + 1, x.r, x.dep + 1});
  }
  cout << endl;
}

int main() {
  int opt, x, y, k;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  print();
  while (m--) {
    cin >> opt;
    if (opt == 1) {
      cin >> x >> y >> k;
      modify(x, y, k);
    } else {
      cin >> x >> y;
      cout << getsum(x, y) << endl;
    }
    print();
    // for (int i = 1; i <= n; i++) {
    //   cout << getnum(i) << ' ';
    // }
    // cout << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}