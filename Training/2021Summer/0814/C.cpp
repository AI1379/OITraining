#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> stk;
int dfs(int dep, int sum, int xorsum, int last, int prelast) {
  if (dep == n) {
    if (sum == xorsum)
      return 0;
    else
      return -1;
  }
  int res;
  for (int i = prelast + 1;i<=1000000000; i++) {
    res = dfs(dep + 1, ((dep % 2 == 0) ? -i : i) + sum, xorsum ^ i, i, last);
    if (res != -1) {
      stk.push(i);
      return i;
    }
  }
}
int main() {
  cin >> n;
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }
  dfs(0, 0, 0, 0, 0);
  while (!stk.empty()) {
    cout << stk.top() << ' ';
    stk.pop();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}