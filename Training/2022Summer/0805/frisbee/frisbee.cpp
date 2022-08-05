#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll kMaxN = 300010;
ll n;
ll h[kMaxN];
ll ans = 0;
deque<pll> dq;
int main() {
#ifndef DEBUG
  freopen("frisbee.in", "r", stdin);
  freopen("frisbee.out", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  
  return 0;
}
