#include <bits/stdc++.h>
using namespace std;
//#include"c:\mySTL\mystl.h"
#define int long long
#define fu(i, l, r) for (int i = l; i <= r; ++i)
#define fd(i, l, r) for (int i = l; i >= r; --i)
#define po printf

const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int T, n, m, s;

inline int read() {
  int a = 0;
  char x;
  int w = 0;
  x = getchar();
  while (!isdigit(x)) {
    if (x == '-') w = 1;
    x = getchar();
  }
  while (isdigit(x)) {
    a = a * 10 + x - '0';
    x = getchar();
  }
  return w ? -a : a;
}

int mX, mG, mF;

struct Guaiwu {
  int X = 0, G = 0, F = 0, U = 0, Hit = 0;
  double XJB = 0;
  vector<int> son;
  void getXJB() { XJB = 1. * U / Hit; }
  void get() {
    X = read();
    G = read();
    F = read();
    U = read();
    Hit = ceil(1. * X / (mG - F)) - 1;
    XJB = 1.0 * U / Hit;
  }
} a[maxn];

priority_queue<pair<double, int> > q;

typedef pair<double, int> pdi;
bool vis[maxn];
int fa[maxn];

int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}

void dfs(int root, int father) {
  for (auto i : a[root].son) {
    if (i != father) {
      fa[i] = root;
      dfs(i, root);
    }
  }
}

void init() {
  cin >> n;
  fu(i, 1, n - 1) {
    int x = read(), y = read();
    a[x].son.push_back(y);
    a[y].son.push_back(x);
  }
  fu(i, 1, n) { fa[i] = i; }
  mX = read();
  mG = read();
  mF = read();
  fu(i, 2, n) {
    a[i].get();
    mX -= a[i].Hit * (a[i].G - mF);
    q.push(make_pair(1.0 * a[i].U / a[i].Hit, i));
  }
  dfs(1, 0);
}

void solve() {
  vis[1] = 1;
  int Fa;
  while (!q.empty()) {
    int now = q.top().second;
    q.pop();
    if (vis[now]) continue;
    vis[now] = 1;
    Fa = find(fa[now]);
    mX += a[now].Hit * a[Fa].U;
    a[Fa].Hit += a[now].Hit;
    a[Fa].U += a[now].U;
    if (!vis[Fa]) q.push(make_pair(1.0 * a[Fa].U / a[Fa].Hit, Fa));
    fa[now] = Fa;
    a[now].Hit = a[now].U = 0;
  }
}

signed main() {
  freopen("t4.in", "r", stdin);
  //	freopen("me.out","w",stdout);
  init();
  solve();
  printf("%lld", mX);
  //	cout<<mX;
  return 0;
}
