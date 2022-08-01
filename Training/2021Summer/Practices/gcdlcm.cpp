#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
vector<int> pri;
bool vis[MAXN];
void eulerPrime() {
  memset(vis, false, sizeof(vis));
  vis[1] = false;
  for (int i = 2; i <= MAXN; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int j = 0; j < pri.size() && i * pri[j] < MAXN; j++) {
      vis[i * pri[j]] = true;
      if (i % pri[j] == 0) {
        break;
      }
    }
  }
}
int gcd(int a, int b) {
  int fa[510], fb[510];
  int maxa = 0, maxb = 0;
  memset(fa,0,sizeof(fa));
  memset(fb,0,sizeof(fb));
  for (int i = 0; i < pri.size() && pri[i] * pri[i] <= a; i++) {
    while (a % pri[i] == 0) {
      a /= pri[i];
      fa[i]++;
      maxa = i;
    }
  }
  for (int i = 0; i < pri.size() && pri[i] * pri[i] <= b; i++) {
    while (b % pri[i] == 0) {
      b /= pri[i];
      fb[i]++;
      maxb = i;
    }
  }
  int ans = 0;
  for (int i = 0; i <= min(maxa, maxb); i++) {
    ans *= pow(pri[i], min(fa[i], fb[i]));
  }
  return ans;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main() {
  int x, y;
  cin >> x >> y;
  eulerPrime();
  int g, l;
  g = gcd(x, y);
  // l = lcm(x, y);
  cout << g << ' ' << l << endl;
  system("pause");
  return 0;
}