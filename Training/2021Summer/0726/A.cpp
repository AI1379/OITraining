#include <bits/stdc++.h>
using namespace std;
bool vis[26];
char lst[26];
int num = 0;
int n;
int main() {
#ifndef DEBUG
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
#endif
  cin >> n;
  char c;
  getchar();
  for (int i = 0; i < n; i++) {
    c = getchar();
    if (!vis[c - 'A']) {
      vis[c - 'A'] = true;
      lst[num++] = c;
    }
  }
  getchar();
  for (int i = 0; i < num; i++) {
    cout << lst[i];
  }
  cout << endl << 26 - num << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}