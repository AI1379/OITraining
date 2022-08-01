#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define ll long long

using namespace std;

priority_queue<pair<double, int> > Q;
int n, h[100001], fa[100001], fath[100001], X, t;
ll Hp[100001], Ad[100001], Def[100001], Num[100001], tim[100001];
bool vis[100001];

struct node {
  int to, next;
} w[200001];

void add(int x, int y) {
  w[++t] = (node){y, h[x]};
  h[x] = t;
  w[++t] = (node){x, h[y]};
  h[y] = t;
}

void dfs(int now, int fath) {
  for (int i = h[now]; i; i = w[i].next)
    if (w[i].to != fath) {
      fa[w[i].to] = now;
      dfs(w[i].to, now);
    }
}

int find(int now) {
  if (now == fath[now]) return now;
  return fath[now] = find(fath[now]);
}  //寻找钡钡【误

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
  }
  fath[1] = 1;
  scanf("%lld%lld%lld", &Hp[1], &Ad[1], &Def[1]);  //牛半仙的血量攻击防御
  for (int i = 2; i <= n; ++i) {
    fath[i] = i;
    scanf("%lld%lld%lld%lld", &Hp[i], &Ad[i], &Def[i], &Num[i]);
    tim[i] = Hp[i] / (Ad[1] - Def[i]);  //计算出要多少次攻击
    if (Hp[i] % (Ad[1] - Def[i]) == 0) tim[i]--;
    Hp[1] -= (Ad[i] - Def[1]) * tim[i];
    Q.push(make_pair(1.0 * Num[i] / tim[i], i));
  }
  dfs(1, 0);
  vis[1] = 1;
  while (!Q.empty()) {
    int now = Q.top().second;
    Q.pop();
    if (vis[now]) continue;
    vis[now] = 1;
    X = find(fa[now]);
    Hp[1] += tim[now] * Num[X];  //补回前面没算防御扣的血
    tim[X] += tim[now];
    Num[X] += Num[now];
    if (!vis[X]) Q.push(make_pair(1.0 * Num[X] / tim[X], X));
    fath[now] = X;
  }
  printf("%lld\n", Hp[1]);
}
