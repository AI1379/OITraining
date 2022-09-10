#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100010;
int n;
vector<int> graph[MAXN];
int in[MAXN];
queue<int>q;
vector<int> loop;
void topsort() {
  int now;
  for (int i = 1; i <= n; i++)
    if (in[i] == 1)q.push(i);
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (auto y : graph[now]) {
      if (in[y] > 1) { //入度>=2的点即为环上的点
        in[y]--;
        loop.push_back(y);
        if (in[y] == 1) {
          q.push(y);
        }
      }
    }
  }
}
int main() {
  int x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    ++in[y];
    graph[x].push_back(y);
  }
  topsort();
  for (auto v : loop) {
    cout << v << ' ';
  }
  return 0;
}
