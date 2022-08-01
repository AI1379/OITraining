#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
ll n;
ll t[MAXN], k[MAXN];
ll tot, des[MAXN * 2];
int main() {
  cin >> n;
  for (int i = 1;i<=n;i++){
    cin >> t[i] >> k[i];
    des[++tot] = t[i];
    des[++tot] = k[i];
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}