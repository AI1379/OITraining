#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
pair<int, int> p[maxn];
int dp[maxn];
int n;
bool cmp(pair<int, int> A, pair<int, int> B) {
  if (A.second != B.second) return A.second < B.second;
  return A.first < B.first;
}
int find(int st) {
  int l = 0, r = n;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (p[mid].second < st) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    int index = find(p[i].first);
    int tmp = (index > 0 ? dp[index] : 0) + p[i].second - p[i].first + 1;
    dp[i] = max(dp[i - 1], tmp);
  }
  cout << dp[n] << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}