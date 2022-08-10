#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
int n;
int v[MAXN], v2[MAXN];
vector<int>graph[MAXN];
vector<int>loop;
inline bool dfs(int x, int pa) {
  if (v[x] == 1) { //再次访问说明到了环的链接点，标记它是环(v[x] = 2)
    v[x] = 2;
    loop.push_back(x);
    v2[x] = 1;
    return true;
  }
  v[x] = 1;
  for (auto y : graph[x]) {
    if (y != pa && dfs(y, x)) {
      if (v[x] != 2) {
        loop.push_back(x);
        v2[x] = 1;
      } else {
        return false;
      }
      return true;
    }
  }
  return false;
//  for (int i = head[x]; ~i; i = nex[i]) {
//    int y = ver[i];
    //如果当前边不是上一条边(没有往回走)并且当前节点在环上
//    if (i != ((in_edge) ^ 1) && dfs(y, i)) { //每次存一个点，靠继续dfs遍历整个环
//      if (v[x] != 2) //当前节点不是衔接点,把环里的点存起来
//        loop[++ cnt] = x, v2[x] = 1, s[cnt] = s[cnt - 1] + edge[i];
//      else {//环的链接点
//        s[st - 1] = s[st] - edge[i];//又转回来（破环成链）
//        return false;
//      }
//      return true;
//    }
//  }
//  return false;
}
int main() {
  return 0;
}
