#include <bits/stdc++.h>
using namespace std;
class BigInt {
#define Value(x, nega) ((nega) ? -(x) : (x))
#define At(vec, index) ((index) < vec.size() ? vec[(index)] : 0)
  static int absComp(const BigInt &lhs, const BigInt &rhs) {
    if (lhs.size() != rhs.size())
      return lhs.size() < rhs.size() ? -1 : 1;
    for (int i = lhs.size() - 1; i >= 0; --i)
      if (lhs[i] != rhs[i])
        return lhs[i] < rhs[i] ? -1 : 1;
    return 0;
  }
  using Long = long long;
  const static int Exp = 9;
  const static Long Mod = 1000000000;
  mutable std::vector<Long> val;
  mutable bool nega = false;
  void trim() const {
    while (val.size() && val.back() == 0)
      val.pop_back();
    if (val.empty())
      nega = false;
  }
  int size() const { return val.size(); }
  Long &operator[](int index) const { return val[index]; }
  Long &back() const { return val.back(); }
  BigInt(int size, bool nega) : val(size), nega(nega) {}
  BigInt(const std::vector<Long> &val, bool nega) : val(val), nega(nega) {}

public:
  friend std::ostream &operator<<(std::ostream &os, const BigInt &n) {
    if (n.size()) {
      if (n.nega)
        putchar('-');
      for (int i = n.size() - 1; i >= 0; --i) {
        if (i == n.size() - 1)
          printf("%lld", n[i]);
        else
          printf("%0*lld", n.Exp, n[i]);
      }
    } else
      putchar('0');
    return os;
  }
  friend BigInt operator+(const BigInt &lhs, const BigInt &rhs) {
    BigInt ret(lhs);
    return ret += rhs;
  }
  friend BigInt operator-(const BigInt &lhs, const BigInt &rhs) {
    BigInt ret(lhs);
    return ret -= rhs;
  }
  BigInt(Long x = 0) {
    if (x < 0)
      x = -x, nega = true;
    while (x >= Mod)
      val.push_back(x % Mod), x /= Mod;
    if (x)
      val.push_back(x);
  }
  BigInt(const char *s) {
    int bound = 0, pos;
    if (s[0] == '-')
      nega = true, bound = 1;
    Long cur = 0, pow = 1;
    for (pos = strlen(s) - 1; pos >= Exp + bound - 1;
         pos -= Exp, val.push_back(cur), cur = 0, pow = 1)
      for (int i = pos; i > pos - Exp; --i)
        cur += (s[i] - '0') * pow, pow *= 10;
    for (cur = 0, pow = 1; pos >= bound; --pos)
      cur += (s[pos] - '0') * pow, pow *= 10;
    if (cur)
      val.push_back(cur);
  }
  friend std::istream &operator>>(std::istream &is, BigInt &n) {
    string s;
    is >> s;
    n = (char *)s.data();
    return is;
  }
  BigInt &operator+=(const BigInt &rhs) {
    const int cap = std::max(size(), rhs.size()) + 1;
    val.resize(cap);
    int carry = 0;
    for (int i = 0; i < cap - 1; ++i) {
      val[i] = Value(val[i], nega) + Value(At(rhs, i), rhs.nega) + carry,
      carry = 0;
      if (val[i] >= Mod)
        val[i] -= Mod, carry = 1;
      else if (val[i] < 0)
        val[i] += Mod, carry = -1;
    }
    if ((val.back() = carry) == -1) // assert(val.back() == 1 or 0 or -1)
    {
      nega = true, val.pop_back();
      bool tailZero = true;
      for (int i = 0; i < cap - 1; ++i) {
        if (tailZero && val[i])
          val[i] = Mod - val[i], tailZero = false;
        else
          val[i] = Mod - 1 - val[i];
      }
    }
    trim();
    return *this;
  }
  friend BigInt operator-(const BigInt &rhs) {
    BigInt ret(rhs);
    ret.nega ^= 1;
    return ret;
  }
  BigInt &operator-=(const BigInt &rhs) {
    rhs.nega ^= 1;
    *this += rhs;
    rhs.nega ^= 1;
    return *this;
  }
  friend BigInt operator*(const BigInt &lhs, const Long &x) {
    BigInt ret = lhs;
    bool negat = (x < 0);
    Long xx = (negat) ? -x : x;
    ret.nega ^= negat;
    ret.val.push_back(0);
    ret.val.push_back(0);
    for (int i = 0; i < ret.size(); i++)
      ret[i] *= xx;
    for (int i = 0; i < ret.size(); i++) {
      ret[i + 1] += ret[i] / Mod;
      ret[i] %= Mod;
    }
    ret.trim();
    return ret;
  }
  BigInt &operator*=(const Long &x) { return *this = *this * x; }
  friend BigInt operator/(const BigInt &lhs, const BigInt &rhs) {
    static std::vector<BigInt> powTwo{BigInt(1)};
    static std::vector<BigInt> estimate;
    estimate.clear();
    if (absComp(lhs, rhs) < 0)
      return BigInt();
    BigInt cur = rhs;
    int cmp;
    while ((cmp = absComp(cur, lhs)) <= 0) {
      estimate.push_back(cur), cur += cur;
      if (estimate.size() >= powTwo.size())
        powTwo.push_back(powTwo.back() + powTwo.back());
    }
    if (cmp == 0)
      return BigInt(powTwo.back().val, lhs.nega ^ rhs.nega);
    BigInt ret = powTwo[estimate.size() - 1];
    cur = estimate[estimate.size() - 1];
    for (int i = estimate.size() - 1; i >= 0 && cmp != 0; --i)
      if ((cmp = absComp(cur + estimate[i], lhs)) <= 0)
        cur += estimate[i], ret += powTwo[i];
    ret.nega = lhs.nega ^ rhs.nega;
    return ret;
  }
  friend BigInt operator/(const BigInt &num, const Long &x) {
    bool negat = (x < 0);
    Long xx = (negat) ? -x : x;
    BigInt ret;
    Long k = 0;
    ret.val.resize(num.size());
    ret.nega = (num.nega ^ negat);
    for (int i = num.size() - 1; i >= 0; i--) {
      ret[i] = (k * Mod + num[i]) / xx;
      k = (k * Mod + num[i]) % xx;
    }
    ret.trim();
    return ret;
  }
  bool operator==(const BigInt &rhs) const {
    return nega == rhs.nega && val == rhs.val;
  }
  bool operator!=(const BigInt &rhs) const {
    return nega != rhs.nega || val != rhs.val;
  }
  bool operator>=(const BigInt &rhs) const { return !(*this < rhs); }
  bool operator>(const BigInt &rhs) const { return !(*this <= rhs); }
  bool operator<=(const BigInt &rhs) const {
    if (nega && !rhs.nega)
      return true;
    if (!nega && rhs.nega)
      return false;
    int cmp = absComp(*this, rhs);
    return nega ? cmp >= 0 : cmp <= 0;
  }
  bool operator<(const BigInt &rhs) const {
    if (nega && !rhs.nega)
      return true;
    if (!nega && rhs.nega)
      return false;
    return (absComp(*this, rhs) < 0) ^ nega;
  }
  void swap(const BigInt &rhs) const {
    std::swap(val, rhs.val);
    std::swap(nega, rhs.nega);
  }
};
BigInt n;
#define ll long long
ll k;
int main() {
#ifndef DEBUG
  freopen("T3.in", "r", stdin);
  freopen("T3.out", "w", stdout);
#endif
  cin >> n >> k;
  cout << n / (k - 1) << endl;
  return 0;
}