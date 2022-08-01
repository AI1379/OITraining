#include <bits/stdc++.h>
using namespace std;
struct node {
  int len;
  int num;
};
int n, m, lu;
int l[10];
int dp[3];
bool vis[32768];
queue<node> q;
void add(int len, int num) {
  if (!vis[len]) {
    q.push((node){len, num});
    vis[len] = true;
  }
}
int main() {
#ifndef DEBUG
  freopen("treehouse.in", "r", stdin);
  freopen("treehouse.out", "w", stdout);
#endif
  node head;
  cin >> n >> m >> l[1] >> l[2] >> l[3] >> lu;
  l[4] = l[1] + l[2];
  l[5] = l[1] + l[3];
  l[6] = l[2] + l[3];
  l[7] = l[1] + l[2] + l[3];
  q.push((node){n, 0});
  vis[n] = true;
  while (!q.empty()) {
    head = q.front();
    q.pop();
    if (head.len == m) {
      cout << head.num << endl;
#ifdef DEBUG
      system("pause");
#endif
      return 0;
    }
    add(head.len / 2, head.num + 1);
    add(head.len - lu, head.num + 1);
    add(lu, head.num + 1);
    for (int i = 1; i <= 7; i++) {
      add(head.len + l[i], head.num + 1);
    }
  }
  cout << "No solution." << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}