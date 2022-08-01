#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
#define val(para) (lower_bound(y + 1, y + tot + 1, (para)) - y - 1)
const ll MAXN = 100010;
struct line {
  ll x, y1, y2, k;
};
ll n;
ll tot;
ll segt[MAXN * 4];
ll y[MAXN * 2];
int main() {
  ll a, b, c, d;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c >> d;
    y[i] = b;
    y[2 * i] = d;
  }
  sort(y + 1, y + 2 * n + 1);
  tot = unique(y + 1, y + 2 * n + 1) - y - 1;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}