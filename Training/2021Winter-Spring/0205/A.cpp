#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct tim {
  ll y, m, d;
  ll wk;
};
tim now;
void add(tim *t) {
  t->d++;
  if (t->d == 32 && (t->m == 1 || t->m == 3 || t->m == 5 || t->m == 7 ||
                     t->m == 8 || t->m == 10 || t->m == 12)) {
    t->d = 1;
    t->m++;
  } else if (t->d == 31 &&
             (t->m == 4 || t->m == 6 || t->m == 9 || t->m == 11)) {
    t->d = 1;
    t->m++;
  } else if ((t->m == 2) &&
             (((t->y % 4 == 0 && t->y % 100 != 0) || t->y % 400 == 0) &&
                  t->d == 30 ||
              (!((t->y % 4 == 0 && t->y % 100 != 0) || t->y % 400 == 0) &&
               t->d == 29))) {
    t->d = 1;
    t->m++;
  }
  if (t->m == 13) {
    t->m = 1;
    t->y++;
  }
  t->wk++;
  if (t->wk == 7) t->wk = 0;
}
ll num[7];
ll n;
int main() {
  scanf("%lld", &n);
  now.y = 1900;
  now.m = 1;
  now.d = 1;
  now.wk = 2;
  while (!(now.d == 1 && now.m == 1 && now.y == 1900 + n)) {
    if (now.d == 13) num[now.wk]++;
    add(&now);
  }
  for (int i = 0; i < 7; i++) {
    printf("%lld ", num[i]);
  }
  printf("\n");
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}
