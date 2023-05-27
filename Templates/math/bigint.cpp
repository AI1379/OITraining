#include <bits/stdc++.h>
constexpr const int kBigIntBits = 1024;
class BigInt {
 private:
  using ContainerType = std::bitset<kBigIntBits>;
  ContainerType container;

 public:
  BigInt(long long &&x) : container(x) {}
  BigInt(ContainerType &&x) : container(x) {}
  friend bool operator!=(const BigInt &lhs, const BigInt &rhs) {
    return (lhs.container ^ rhs.container).any();
  }
  friend bool operator<(const BigInt &lhs, const BigInt &rhs) {}
  friend BigInt operator+=(BigInt &lhs, const BigInt &rhs) {}
  friend BigInt operator+(BigInt lhs, const BigInt &rhs) { return lhs += rhs; }
  friend BigInt operator-(const BigInt &lhs) {
    return BigInt(~lhs.container) + 1;
  }
  friend BigInt operator-(const BigInt &lhs, const BigInt &rhs) {
    return lhs + (-rhs);
  }
  friend BigInt operator-=(BigInt &lhs, const BigInt &rhs) {
    return lhs += (-rhs);
  }
  friend BigInt operator*=(BigInt &lhs, const BigInt &rhs) {}
};
int main() {}