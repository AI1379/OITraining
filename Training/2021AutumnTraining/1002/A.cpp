#include <bits/stdc++.h>
using namespace std;
struct node {
  int w, pos;
};
int n, k;
node l[50010];
int e[11];
bool cmp(node a, node b) { return a.w != b.w ? a.w > b.w : a.pos < b.pos; }
int main() {
  cin >> n >> k;
  for (int i = 0; i < 10; i++) cin >> e[i];
  for (int i = 0; i < n; i++) {
    cin >> l[i].w;
    l[i].pos = i + 1;
  }
  sort(l, l + n, cmp);
  for (int i = 0; i < n; i++) l[i].w += e[i % 10];
  sort(l, l + n, cmp);
  for (int i = 0; i < k; i++) cout << l[i].pos << ' ';
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}