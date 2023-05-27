#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define ll long long
#define state tuple<ll, ll, ll, ll>
ll a, b, c, d;
state getlight(state x) {
  state y;
  get<0>(y) = get<0>(x) + get<1>(x) / 2 + get<2>(x) / 2 + get<3>(x) / 4;
  get<1>(y) = get<1>(x) + get<0>(x) / 2 + get<3>(x) / 2 + get<2>(x) / 4;
  get<2>(y) = get<2>(x) + get<3>(x) / 2 + get<0>(x) / 2 + get<1>(x) / 4;
  get<3>(y) = get<3>(x) + get<2>(x) / 2 + get<1>(x) / 2 + get<0>(x) / 4;
  return y;
}
ll getval(state x) { return get<0>(x) + get<1>(x) + get<2>(x) + get<3>(x); }
bool operator<(state a, state b) { return getval(a) > getval(b); }
map<state, bool> vis;
bool check(state x) {
  if (get<0>(x) < 0 || get<1>(x) < 0 || get<2>(x) < 0 || get<3>(x) < 0)
    return false;
  state y = getlight(x);
  return get<0>(y) >= a && get<1>(y) >= b && get<2>(y) >= c && get<3>(y) >= d;
}
#define pushst(v)                                                              \
  --get<v>(nxt);                                                               \
  if (check(nxt) && !vis[nxt])                                                 \
    q.push(nxt), flag = vis[nxt] = true;                                       \
  nxt = tmp;

int main() {
  cin >> a >> b >> c >> d;
  bool flag;
  ll ans = (1ll << (sizeof(ll) * 8 - 2));
  state init = make_tuple(a, b, c, d), tmp, nxt;
  queue<state> q;
  q.push(init);
  while (!q.empty()) {
    nxt = tmp = q.front();
    q.pop();
    flag = false;
    pushst(0);
    pushst(1);
    pushst(2);
    pushst(3);
    if (!flag && check(tmp)) {
      ans = min(ans, getval(tmp));
      if (ans == 76) {
        cout << get<0>(tmp) << ' ' << get<1>(tmp) << ' ' << get<2>(tmp) << ' '
             << get<3>(tmp) << endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}