/**
# 最大面积

## 题目描述

有n条线段，围成一个三角形，使得其面积最大。

## 输入格式

第1行 一个数n。

第2~n+1行，每行一个整数，第i+1行表示第i条线段的长度。

## 输出格式

答案保留两位小数；如无答案，输出“-1”。

## 样例 #1

### 样例输入 #1

```
3
3
9
10
```

### 样例输出 #1

```
13.27
```

## 提示

对于 100% 的数据，保证 3≤n≤40，1≤li ≤40。
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 63;
const ll MAXL = 1023;
ll n, s;
ll len[MAXN];
bool dp[MAXL][MAXL];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> len[i];
    s += len[i];
  }
  dp[0][0] = true;
  for (int k = 1; k <= n; ++k) {
    for (int i = s / 2; i >= 0; --i) {
      for (int j = s / 2; j >= 0; --j) {
        dp[i][j] = dp[i][j] || (i - len[k] >= 0 && dp[i - len[k]][j]) ||
                   (j - len[k] >= 0 && dp[i][j - len[k]]);
      }
    }
  }
  ll ans = -1;
  for (int i = 1; i <= s / 2; ++i) {
    for (int j = 1; j <= s / 2; ++j) {
      if (i + j > s - i - j && dp[i][j]) {
        ans = max(ans, s * (s - 2 * i) * (s - 2 * j) * (s - 2 * (s - i - j)));
      }
    }
  }
  if (ans == -1)
    cout << -1 << endl;
  else
    cout << fixed << setprecision(2) << sqrt((double)(ans) / 16.0) << endl;

  return 0;
}
