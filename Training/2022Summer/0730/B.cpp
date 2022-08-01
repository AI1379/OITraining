#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

using namespace std;
#define ll long long
#define ld double
const ll MAXN = 1023;
struct Single {
  std::shared_ptr<std::string> title_ptr = nullptr;
  ld level, acc;
  ld rks;
};
ll n;
Single list[MAXN];
ld rks = (ld)(0);
bool comp(const Single &lhs, const Single &rhs) { return lhs.rks > rhs.rks; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    list[i].title_ptr = make_shared<std::string>("");
    cin >> (*list[i].title_ptr);
    cin >> list[i].level >> list[i].acc;
    list[i].rks =
        (list[i].acc * list[i].acc * list[i].level -
         (ld)(110) * list[i].acc * list[i].level + (ld)(3025) * list[i].level) /
        (ld)(2025);
  }
  sort(list + 1, list + n + 1, comp);
  for (int i = 1; i <= 10; i++) {
    rks = rks + list[i].rks;
  }
  rks = rks / (ld)(10);
  cout << std::fixed << std::setprecision(2);
  cout << rks << endl;
  for (int i = 1; i <= n; i++) {
    cout << (*(list[i].title_ptr)) << ' ' << list[i].rks << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}