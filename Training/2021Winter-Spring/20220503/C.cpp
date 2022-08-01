#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;
#define ll long long
const ll MAXN = 410;
const ll dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
const ll dy[] = {2, 1, -2, -1, 2, 1, -2, -1};
struct node {
  ll first, second, pos;
};
static ll n, m, x, y;
static ll mp[MAXN][MAXN];
queue<node> q;
static node tmp;
#define CHECK(s)                                                               \
  mp[s.first + dx[k]][s.second + dy[k]] == -1 && 1 <= s.first + dx[k] &&       \
      s.first + dx[k] <= n && 1 <= s.second + dy[k] && s.second + dy[k] <= m
int main() {
  memset(mp, -1, sizeof(mp));
  cin >> n >> m >> x >> y;
  mp[x][y] = 0;
  q.push(node{x, y, 0});
  while (!q.empty()) {
    tmp = q.front();
    q.pop();
    for (int k = 0; k < 8; k++) {
      if (CHECK(tmp)) {
        q.push(node{tmp.first + dx[k], tmp.second + dy[k], tmp.pos + 1});
        mp[tmp.first + dx[k]][tmp.second + dy[k]] = tmp.pos + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%-5lld", mp[i][j]);
    }
    printf("\n");
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}