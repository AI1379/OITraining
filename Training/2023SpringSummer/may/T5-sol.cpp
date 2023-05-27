#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long d[50010];
bool check(long long value) {
  long long cnt = 0, i, now = 0;
  for (i = 1; i <= n; i++)
    if (d[i] - d[now] < value)
      cnt++;
    else
      now = i;
  return d[n + 1] - d[now] >= value && cnt <= m;
}
int main() {
  long long i;
  cin >> n >> m;
  for (i = 1; i <= n + 1; i++)
    cin >> d[i];
  long long left = 1, right = d[n + 1], mid, ans = 0;
  while (left <= right) {
    mid = (left + right) / 2;
    if (check(mid)) {
      ans = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  cout << ans;
  return 0;
}
