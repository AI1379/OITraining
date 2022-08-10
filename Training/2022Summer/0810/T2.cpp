#include <iostream>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll MAXN = 100010;
struct Node {
  ll val, size;
  ll son[2];
};
ll n;
ll val[MAXN];
Node cartesian[MAXN];
ll root;
ll stk[MAXN], top = 0;
void build() {
  for (int i = 1; i <= n; i++) {
    cartesian[i].val = val[i];
    while (top && cartesian[stk[top]].val < val[i]) {
      cartesian[i].son[0] = stk[top--];
    }
    cartesian[stk[top]].son[1] = i;
    stk[++top] = i;
  }
  root = stk[1];
}
void dfs(ll cur) {
  if (cur == 0) return;
  dfs(cartesian[cur].son[0]);
  dfs(cartesian[cur].son[1]);
  cartesian[cur].size = cartesian[cartesian[cur].son[0]].size
                        + cartesian[cartesian[cur].son[1]].size
                        + 1;
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  build();
  dfs(root);
  for (int i = 1; i <= n; i++) {
    cout << cartesian[i].size << ' ';
  }
  cout << endl;
  return 0;
}
