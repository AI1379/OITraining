#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  const int up = 5e6;
  const int R = 1e6;
  int mx = 0;
  for (int i = 1; i <= n; i++)
    mx += (a[i] < R);
  vector<int> pre(up + 1, 0);
  for (int i = 1; i <= n; i++)
    pre[a[i]] += 1;
  for (int i = 2; i <= up; i++)
    pre[i] += pre[i - 1];
  auto query = [&](int l, int r) { return pre[r] - pre[l - 1]; };
  vector<int> t(up + 1, 0);
  vector<pair<int, int>> p(up + 1, {-1, -1});
  for (int i = 1; i <= R; i++) {
    for (int j = i, d = 1; j <= up; j += i, d += 1) {
      int L = p[d].first;
      int R = p[d].second;
      int L2 = j;
      int R2 = min(j + i - 1, up);
      if (R < L2) {
        p[d] = {L2, R2};
        t[d] += query(L2, R2);
      } else {
        if (R < R2) {
          p[d] = {L2, R2};
          t[d] += query(R + 1, R2);
        }
      }
    }
  }

  mx = max(mx, *max_element(t.begin() + 1, t.end()));
  cout << mx << '\n';

  return 0;
}
