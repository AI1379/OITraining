#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> tree[100010];  // 邻接表

struct node {
  int lev, t, pos;
  node(int a, int b, int c) : lev(a), t(b), pos(c) {}
};

ll blood[100010], attack[100010], def[100010], lev[100010], t[100010];
bool vis[100010];

int rt[100010];  // 父节点
int fa[100010];  // 并查集
struct cmp {
  bool operator()(node a, node b) { return a.lev * b.t < b.lev * a.t; }
};

priority_queue<node, vector<node>, cmp> q;
int find(int x) { return (fa[x] == x) ? x : (fa[x] = find(fa[x])); }

void dfs(int root, int u) {
  for (int i = 0; i < tree[u].size(); i++) {
    if (tree[u][i] != root) {
      rt[tree[u][i]] = u;
      dfs(u, tree[u][i]);
    }
  }
}

int main() {
  int x, y;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  cin >> blood[1] >> attack[1] >> def[1];
  fa[1] = 1;
  for (int i = 2; i <= n; i++) {
    fa[i] = i;  // 并查集初始化
    cin >> blood[i] >> attack[i] >> def[i] >> lev[i];

    // 打爆他的次数
    t[i] = blood[i] / (attack[1] - def[i]);
    if (blood[i] % (attack[1] - def[i]) == 0) t[i]--;
    // 自己扣的血
    blood[1] -= (attack[i] - def[1]) * t[i];

    // 进堆
    q.push(node(lev[i], t[i], i));
    // q.push(i);
    // heap[hSize++] = i;
  }
  dfs(1, 0);
  int top, root;
  vis[1] = true;
  // make_heap(heap, heap + hSize, cmp);
  while (!q.empty()) {
    // 取堆顶
    top = q.top().pos;
    q.pop();
    if (vis[top]) continue;
    vis[top] = true;
    root = find(rt[top]);
    // 加回没算防御的血
    blood[1] += lev[root] * t[top];
    t[root] += t[top];
    lev[root] += lev[top];
    // 维护堆
    if (!vis[root]) q.push(node(lev[root], t[root], root));
    // make_heap(heap, heap + hSize, cmp);
    // 并查集合并
    fa[top] = root;
  }
  cout << blood[1] << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}