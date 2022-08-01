#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n;
vector<int> pri;
bool vis[MAXN];
void eulerPrime() {
  memset(vis, false, sizeof(vis));
  vis[1]=false;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int j = 0; j < pri.size() && i * pri[j] < n; j++) {
      vis[i * pri[j]] = true;
      if (i % pri[j] == 0) {
        break;
      }
    }
  }
}
int main() {
  cin>>n;
  eulerPrime();
  for(int i=0;i<pri.size()-1;i++){
    cout<<pri[i]<<' ';
  }
  system("pause");
  return 0;
}