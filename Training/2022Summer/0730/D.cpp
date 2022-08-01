#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#define ll long long
#define abs(x) ((x) > 0 ? (x) : (-(x)))
const ll MAXN = 100010;
const ll MAXM = 200010;
struct Node {
  ll v;
  ll number;
};
struct Edge {
  ll u, v;
};
ll n, m;
std::vector<Node> graph[MAXN];
ll degree[MAXN];
Edge edges[MAXM];
std::vector<ll> self_circle[MAXN];
bool vis_self_circle[MAXN];
bool vis_edge[MAXM];
ll first_not_used[MAXN];
std::vector<ll> ans;
Node makeNode(ll v, ll number) {
  Node res;
  res.v = v;
  res.number = number;
  return res;
}
stack<ll> curr_path;
stack<ll> ans_stk;
void hierholzer(ll u) {
  ll cur = u, next;
  curr_path.push(u);
  while (!curr_path.empty()) {
    if (degree[cur]) {
      curr_path.push(u);
      while (first_not_used[cur] < graph[cur].size() &&
             vis_edge[abs(graph[cur][first_not_used[cur]].number)]) {
        ++first_not_used[cur];
      }
      next = graph[cur][first_not_used[cur]].v;
      ans_stk.push(graph[cur][first_not_used[cur]].number);
      --degree[cur];
      --degree[next];
      vis_edge[abs(graph[cur][first_not_used[cur]].number)] = true;
      ++first_not_used[cur];
      cur = next;
    } else {
      if (!ans_stk.empty()) {
        ans.push_back(ans_stk.top());
        ans_stk.pop();
      }
      cur = curr_path.top();
      curr_path.pop();
    }
  }
}
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    if (u != v) {
      graph[u].push_back(makeNode(v, i));
      graph[v].push_back(makeNode(u, -i));
      edges[i].u = u;
      edges[i].v = v;
      degree[u]++;
      degree[v]++;
    } else {
      self_circle[u].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (degree[i] == 0 || degree[i] % 2 == 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  u = 1;
  hierholzer(u);
  for (auto e : ans) {
    if (e > 0) {
      v = edges[e].v;
    } else {
      v = edges[-e].u;
    }
    if (!vis_self_circle[u]) {
      for (auto x : self_circle[u]) {
        cout << x << ' ';
      }
      vis_self_circle[u] = true;
    }
    cout << -e << ' ';
    u = v;
  }
  return 0;
}