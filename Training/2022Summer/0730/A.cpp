#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 410;
ll n, m, ed = 0;
bool mp[MAXN][4];
int main() {
  ll a, k;
#ifndef DEBUG
  ios::sync_with_stdio(false);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a >> k;
    mp[a][k - 1] = true;
    ed = max(ed, a);
  }
  for (int i = ed; i >= 1; i--) {
    for (int j = 0; j < 4; j++) {
      if (mp[i][j]) {
        cout << "_";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}