#include <bits/stdc++.h>
using namespace std;
long long a[400001], c[400001], x, y, z, q, tag[400001], tag2[400001];
int n, m;
struct node {
  int l, r;
} s[400001];
void build(int p, int l, int r) {
  tag[p] = 0;
  tag2[p] = 1;
  s[p].l = l;
  s[p].r = r;
  if (l == r) {
    c[p] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  c[p] = c[p * 2] + c[p * 2 + 1] % q;
  // cout<<p<<" "<<c[p]<<endl;
}
void spread(int p) {
  tag2[p * 2] *= tag2[p];
  tag2[p * 2] %= q;
  tag2[p * 2 + 1] *= tag2[p];
  tag2[p * 2 + 1] %= q;
  c[p * 2] = (c[p * 2] + tag[p] * (s[p * 2].r - s[p * 2].l + 1)) * tag2[p] % q;
  c[p * 2 + 1] =
      (c[p * 2 + 1] + tag[p] * (s[p * 2 + 1].r - s[p * 2 + 1].l + 1)) *
      tag2[p] % q;
  // ---
  tag[p * 2] = (tag[p * 2] * tag2[p] + tag[p]) % q;
  tag[p * 2 + 1] = (tag[p * 2 + 1] * tag2[p] + tag[p]) % q;
  tag[p] = 0;
  tag2[p] = 1;
}
void add(int p, int l, int r, int x, int y, int k) {
  int mid = (l + r) >> 1;
  if (l >= x && r <= y) {
    //	spread(p);
    c[p] += k * (r - l + 1);
    tag[p] += k;
    return;
  }
  spread(p);
  if (x <= mid)
    add(p * 2, l, mid, x, y, k);
  if (y > mid)
    add(p * 2 + 1, mid + 1, r, x, y, k);
  c[p] = (c[p * 2] + c[p * 2 + 1]) % q;
}
void mult(int p, int l, int r, int x, int y, int k) {
  if (l >= x && r <= y) {
    tag2[p] = tag2[p] * k % q;
    tag[p] = tag[p] * k % q;
    c[p] = c[p] * k % q;
    return;
  }
  int mid = (l + r) >> 1;
  spread(p);
  if (x <= mid)
    mult(p * 2, l, mid, x, y, k);
  if (y > mid)
    mult(p * 2 + 1, mid + 1, r, x, y, k);
  c[p] = (c[p * 2] + c[p * 2 + 1]) % q;
}
long long sum(int p, int l, int r, int x, int y) {
  long long ans = 0;
  // cout<<p<<" "<<c[p]<<endl;
  if (x <= l && r <= y) {
    return c[p];
  }
  int mid = (l + r) >> 1;
  spread(p);
  if (x <= mid)
    ans += sum(p * 2, l, mid, x, y);
  if (y > mid)
    ans += sum(p * 2 + 1, mid + 1, r, x, y);
  return ans % q;
}
int main() {
  cin >> n >> m >> q;
  // q = 1000000;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    cin >> x;
    if (x == 1) {
      cin >> x >> y >> z;
      mult(1, 1, n, x, y, z);
    } else if (x == 2) {
      cin >> x >> y >> z;
      add(1, 1, n, x, y, z);
    } else {
      cin >> x >> y;
      cout << sum(1, 1, n, x, y) << endl;
    }
  }
}
