#include <iostream>
using namespace std;
#define ll long long
ll m[3], n[3];
int main() {
  for (int i = 0; i < 3; i++)
    cin >> m[i] >> n[i];
  for (int idx = 0, i, j; idx < 100; idx++) {
    i = idx % 3;
    j = (i + 1) % 3;
    if (n[i] <= m[j] - n[j]) {
      n[j] += n[i];
      n[i] = 0;
    } else {
      n[i] -= (m[j] - n[j]);
      n[j] = m[j];
    }
  }
  for (int i = 0; i < 3; i++)
    cout << n[i] << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}