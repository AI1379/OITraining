#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n;
ll val[MAXN];
ll pre[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    pre[i] = val[i] + pre[i - 1];
  }
  
  return 0;
}