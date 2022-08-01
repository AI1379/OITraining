#include <bits/stdc++.h>
using namespace std;
pair<int, int> lst[100];
int main() {
  int n;
  string str;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> str;
    lst[i].second = i;
    for (int j = 0; j < str.size(); j++) {
      switch (str[j]) {
        case '-':
          continue;
        case 'W':
          lst[i].first += 3;
          break;
        case 'L':
          lst[j + 1].first += 3;
          break;
        case 'D':
          lst[i].first += 1;
          lst[j + 1].first += 1;
          break;
      }
    }
  }
  sort(lst + 1, lst + n + 1, [](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  });
  for (int i = 1; i <= n; i++) {
    if (i != 1 && lst[i].first < lst[i - 1].first) break;
    cout << lst[i].second << ' ';
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}