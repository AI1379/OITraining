#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXS = 3000010;
char s[MAXS];
ll q, n;
ll ans;
ll x;
char c;
int main() {
  scanf("%lld", &q);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] != s[i - 1])
      ++ans;
  }
  printf("%lld\n", (ans + 1) / 2);
  for (int i = 1; i <= q; ++i) {
    scanf("%lld %c", &x, &c);
    if (s[x] == c)
      goto output;
    if (s[x - 1] == c && s[x + 1] == c) {
      ans -= 2;
    } else if (s[x - 1] == c || s[x + 1] == c) {
      ans -= 1;
    }
    if (s[x - 1] == s[x] && s[x] == s[x + 1]) {
      ans += 2;
    } else if (s[x - 1] == s[x] || s[x + 1] == s[x]) {
      ans += 1;
    }
    s[x] = c;
  output:
    printf("%lld\n", (ans + 1) / 2);
  }
  return 0;
}