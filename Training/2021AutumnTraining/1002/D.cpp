#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[210];
vector<pair<int, int> > graph[210];
int dis[210];
bool vis[210];
int heap[210];
bool inHeap[210];
bool cmp(int a, int b) { return dis[a] > dis[b]; }
int main() {
  int x, y, z;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    graph[x].push_back(make_pair(y, z));
    graph[y].push_back(make_pair(x, z));
  }
  int q;
  int hSize;
  int h;
  cin >> q;
  while (q--) {
    cin >> x >> y >> z;
    if (z > t[y]) {
      cout << -1 << endl;
      continue;
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    memset(inHeap, false, sizeof(inHeap));
    dis[x] = 0;
    // vis[x] = true;
    heap[0] = x;
    inHeap[x] = true;
    hSize = 1;
    make_heap(heap, heap + hSize, cmp);
    while (hSize > 0) {
      // for (int i = 0; i < hSize; i++) cout << heap[i] << ' ';
      // cout << endl;
      h = heap[0];
      pop_heap(heap, heap + hSize, cmp);
      hSize--;
      inHeap[h] = false;
      // if (vis[h]) continue;
      // vis[h] = true;
      for (int i = 0; i < graph[h].size(); i++) {
        if (t[graph[h][i].first] <= z &&
            dis[graph[h][i].first] > dis[h] + graph[h][i].second) {
          dis[graph[h][i].first] = dis[h] + graph[h][i].second;
          if (!inHeap[graph[h][i].first]) {
            heap[hSize] = graph[h][i].first;
            inHeap[graph[h][i].first] = true;
            hSize++;
          }
          make_heap(heap, heap + hSize, cmp);
        }
      }
    }
    // for (int i = 0; i < n; i++)
    //   cout << (dis[i] == 0x3f3f3f3f ? -1 : dis[i]) << ' ';
    // cout << endl;
    if (dis[y] == 0x3f3f3f3f)
      cout << -1 << endl;
    else
      cout << dis[y] << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}