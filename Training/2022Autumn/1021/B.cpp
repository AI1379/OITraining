#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n;
ll state[MAXN];
int main() {
  string s;
  ll x;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s >> x;
    if (s == "ADD") {
      state[i] = state[i - 1] + x;
    } else if (s == "SUB") {
      state[i] = state[i - 1] - x;
    } else if (s == "BACK") {
      state[i] = state[i - x - 1];
    } else if (s == "SET") {
      state[i] = x;
    }
    cout << state[i] << ' ';
  }
  return 0;
}