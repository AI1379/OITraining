#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
ll n;
ll trie[MAXN * 20][2];
ll fa[MAXN * 20];
ll val[MAXN];
ll pos[MAXN];
ll cnt[MAXN];
ll node[MAXN * 20];
bool vis[MAXN];
ll rt = 0, tot = 0;
struct Node {
  ll u, w, pre;
  Node(ll u_, ll w_, ll pre_) : u(u_), w(w_), pre(pre_) {}
};
struct cmp {
  bool operator()(const Node &lhs, const Node &rhs) const {
    return lhs.w > rhs.w;
  }
};
priority_queue<Node, vector<Node>, cmp> q;
void ins(ll t) {
  if (rt == 0)
    rt = ++tot;
  ll cur = rt, x = val[t];
  ++cnt[cur];
  for (int idx = 30; idx >= 0; --idx) {
    cur = (trie[cur][(x >> idx) & 1] == 0 ? trie[cur][(x >> idx) & 1] = ++tot
                                          : trie[cur][(x >> idx) & 1]);
    ++cnt[cur];
  }
  pos[t] = cur;
  node[pos[t]] = t;
}
void del(ll t) {
  ll cur = rt, x = val[t];
  --cnt[cur];
  for (int idx = 30; idx >= 0; --idx) {
    if (cnt[trie[cur][(x >> idx) & 1]] == 1) {
      cur = trie[cur][(x >> idx) & 1];
      trie[fa[cur]][(x >> idx) & 1] = 0;
    } else {
      cur = trie[cur][(x >> idx) & 1];
    }
    --cnt[cur];
  }
}
void getnxt(ll t, ll &v, ll &w) {
  ll cur = fa[pos[t]], x = val[t], idx = 0;
  w = 0;
  for (; idx <= 30; ++idx) {
    if (trie[cur][((x >> idx) & 1) ^ 1]) {
      cur = trie[cur][((x >> idx) & 1) ^ 1];
      w |= (1ll << idx);
      --idx;
      break;
    } else {
      cur = fa[cur];
    }
    // cout << w << endl;
  }
  for (; idx >= 0; --idx) {
    if (trie[cur][(x >> idx) & 1]) {
      cur = trie[cur][(x >> idx) & 1];
    } else {
      w |= (1ll << idx);
      cur = trie[cur][((x >> idx) & 1) ^ 1];
    }
    // cout << w << endl;
  }
  v = node[cur];
}
ll ans = 0;
int main() {
  // freopen("tree.in", "r", stdin);
  // freopen("tree.out", "w", stdout);
  ll u, v, w;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    ins(i);
  }
  // for (int i = 1; i <= n; ++i) {
  // cout << pos[i] << ' ';
  // }
  // cout << endl;
  for (int i = 1; i <= tot; ++i) {
    fa[trie[i][0]] = fa[trie[i][1]] = i;
  }
  q.emplace(1, 0, 0);
  while (!q.empty()) {
    auto tmp = q.top();
    q.pop();
    u = tmp.u;
    if (vis[u]) {
      getnxt(tmp.pre, v, w);
      if (v)
        q.emplace(v, w, tmp.pre);
      continue;
    }
    // cout << q.size() << ' ' << tmp.w << endl;
    ans += tmp.w;
    del(u);
    vis[u] = true;
    getnxt(u, v, w);
    // cout << u << ' ' << v << ' ' << w << endl;
    if (v)
      q.emplace(v, w, u);
    getnxt(tmp.pre, v, w);
    // cout << tmp.pre << ' ' << v << ' ' << w << endl;
    if (v)
      q.emplace(v, w, tmp.pre);
  }  
  cout << ans << endl;
  return 0;
}