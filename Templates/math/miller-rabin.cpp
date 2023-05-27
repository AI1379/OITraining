#include <iostream>
using namespace std;
#define ll long long
ll qpow(ll a, ll b, ll m) {
  static ll res;
  res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
// 据称用这串数字代替随机数可以保证在2^64以内必然正确
constexpr const ll kMillerRobinBase[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool millerRabin(ll n) {
  // 特判
  if (n < 3 || n % 2 == 0) return n == 2;
  static ll a = n - 1, b = 0, base, val, idx, i;
  // 二次探测定理:
  // 若p为奇素数, 则x^2===1(mod p)的解为x===1(mod p)或x===p-1(mod p)
  // Miller-Rabin结合了费马小定理和二次探测定理
  // 费马小定理为base^(n-1)===1(mod n),取a,b使得b*2^a==n-1
  while (a % 2 == 0) {
    a >>= 1;
    ++b;
  }
  for (idx = 0; idx < 7; ++idx) {
    base = kMillerRobinBase[idx];
    val = qpow(base, a, n);
    if (val <= 1 || val == n - 1) {
      // val<=1直接通过费马小定理 并且后面循环必然恒为1 continue掉
      // val==n-1 根据二次探测定理 val^2能通过费马小定理 也continue
      continue;
    }
    for (i = 0; i < b; ++i) {
      if (val == n - 1) {
        // 通过二次探测定理和费马小定理
        break;
      }
      val = val * val % n;
    }
    if (i >= b) {
      return false;
    }
  }
  return true;
}
ll n;
int main() {
  cin >> n;
  if (millerRabin(n)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
