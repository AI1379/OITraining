#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define ll long long
struct cow {
  ll id, a, t;
};
struct cmp {
  bool operator()(const cow &a, const cow &b) { return a.id > b.id; }
};
const ll MAXN = 100010;
ll n;
cow lst[MAXN];
ll tim, ans;
priority_queue<cow, vector<cow>, cmp> q;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> lst[i].a >> lst[i].t;
    lst[i].id = i;
  }
  sort(lst + 1, lst + n + 1,
       [](const cow &a, const cow &b) -> bool { return a.a < b.a; });
  for (int i = 1; i <= n + 1;) {
    q.push(lst[i]);
    tim = lst[i].a;
    i++;
    while (!q.empty()) {
      cow x = q.top();
      q.pop();
      ans = max(ans, tim - x.a);
      tim += x.t;
      for (int j = i; j <= n; j++) {
        if (lst[i].a <= tim) {
          q.push(lst[i]);
          i++;
        } else {
          break;
        }
      }
    }
  }
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}