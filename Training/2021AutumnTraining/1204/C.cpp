#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 50010;
struct node {
  ll num, w;
};
bool cmp(node x, node y) { return x.w > y.w || (x.w == y.w && x.num < y.num); }
node p[MAXN];
ll E[15], n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= 10; i++) cin >> E[i];
  for (int i = 1; i <= n; i++) {
    cin >> p[i].w;
    p[i].num = i;
  }
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i <= n; i++) p[i].w += E[(i - 1) % 10 + 1];
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i <= k; i++) cout << p[i].num << ' ';
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}