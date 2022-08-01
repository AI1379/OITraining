#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[1000010];
int sum[1000010];
int ans = 0x80000000;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  int mins = 0, maxs = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, sum[i] - mins);
    mins = min(mins, sum[i]);
    maxs = max(maxs, sum[i]);
    ans = max(ans, sum[n] - sum[i] + maxs);
  }
  cout << ans << endl;
  return 0;
}