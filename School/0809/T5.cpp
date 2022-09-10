#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n;
bool isprime[MAXN];
bool avail[MAXN];
vector<ll> prime;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  memset(isprime, true, sizeof(isprime));
  memset(avail, true, sizeof(avail));
  isprime[1] = false;
  avail[1] = false;
  for (ll i = 2; i <= n; i++) {
    if (isprime[i]) {
      prime.push_back(i);
      avail[i] = false;
      if (i * i <= n)
        avail[i * i] = false;
    }
    for (auto p : prime) {
      if (p * i > n)
        break;
      isprime[p * i] = false;
      if (i % p == 0) {
        break;
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    for (auto p : prime) {
      if (i * p * p > n) {
        break;
      }
      avail[i * p * p] = false;
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (avail[i]) {
      cout << i << ' ';
    }
  }
  cout << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}