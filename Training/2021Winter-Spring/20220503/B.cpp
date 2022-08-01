#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 10010;
static ll n, m;
static ll a;
static ll x, y;
priority_queue<ll, vector<ll>, greater<ll>> q;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (i <= m) {
      q.push(a);
    } else {
      q.push(a + q.top());
      q.pop();
    }
  }
  x = 0;
  while (!q.empty()) {
    x = q.top();
    q.pop();
  }
  cout << x << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}