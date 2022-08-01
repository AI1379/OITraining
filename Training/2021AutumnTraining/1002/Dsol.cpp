#include <cstdio>
#include <iostream>
const int N = 210;
using namespace std;
int n, m;
int t[N];
int arc[N][N];
int main() {
  int i, j, k;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> t[i];
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      arc[i][j] = 1e9;
    }
  for (i = 0; i < n; i++) arc[i][i] = 0;
  int s1, s2, s3;
  for (i = 0; i < m; i++) {
    cin >> s1 >> s2 >> s3;
    arc[s1][s2] = arc[s2][s1] = s3;
  }
  int q;
  cin >> q;
  int now = 0;
  for (k = 0; k < q; k++) {
    cin >> s1 >> s2 >> s3;
    while (t[now] <= s3 && now < n) {
      for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          if (arc[i][j] > arc[i][now] + arc[j][now])
            arc[i][j] = arc[j][i] = arc[i][now] + arc[j][now];
      now++;
    }
    if (t[s1] > s3 || t[s2] > s3)
      cout << -1 << endl;
    else {
      if (arc[s1][s2] == 1e9)
        cout << -1 << endl;
      else
        cout << arc[s1][s2] << endl;
    }
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}