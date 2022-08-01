#include <bits/stdc++.h>
using namespace std;
struct edge {
  int p, q, r;
};
struct req {
  int k, v;
};
int n, q;
edge edges[100010];
req k[100010];
vector<int> graph[100010];
int rank[100010];
int fa[100010];
int fd(int x) { return fa[x] = (fa[x] == x ? fa[x] : fd(fa[x])); }
void un(int x, int y) {
  int a = fd(x), b = fd(y);
  if (a != b) {
    fa[a] = b;
    rank[a] += rank[b];
  }
}
bool cmp(int a, int b) { return a > b; }
bool cmpedge(edge a, edge b) { return a.r > b.r; }
bool cmpreq(req a, req b) { return a.k > b.k; }
int main() {
  int tmp;
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    cin >> edges[i].p >> edges[i].q >> edges[i].r;
    graph[edges[i].p].push_back(edges[i].q);
    graph[edges[i].q].push_back(edges[i].p);
  }
  for (int i = 0; i < q; i++) {
    cin >> k[i].k >> k[i].v;
  }
  sort(k, k + q, cmpreq);
  sort(edges, edges + n - 1, cmpedge);
  for (int i = 1; i <= n; i++) {
    rank[i] = 1;
    fa[i] = i;
  }
  int j = 0;
  for (int i = 0; i < q; i++) {
    while (edges[j].r >= k[i].k) {
      un(edges[j].p, edges[j].q);
    }
    cout << rank[fd(k[i].v)] << endl;
  }
  return 0;
}
