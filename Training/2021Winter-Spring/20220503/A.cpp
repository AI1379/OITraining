#include <cstdio>
#include <cstdlib>
using namespace std;
#define ll long long
ll t;
int main() {
  scanf("%lld", &t);
  printf("%lld:%lld:%lld\n", t / 3600, (t % 3600) / 60, t % 60);
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}