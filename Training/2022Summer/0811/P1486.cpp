#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
#include <utility>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
ll n, m, delta = 0;
typedef __gnu_pbds::tree<pll, __gnu_pbds::null_type, greater<pll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    RBTree;
RBTree rbt, other;
int main() {
  char opt;
  ll k, ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> opt >> k;
    if (opt == 'I') {
      k += delta;
      if (k >= m)
        rbt.insert(make_pair(k, i));
    } else if (opt == 'A') {
      m -= k;
      delta -= k;
    } else if (opt == 'S') {
      m += k;
      delta += k;
      rbt.split(make_pair(m, -1), other);
      ans += other.size();
      other.clear();
    } else {
      if (rbt.size() >= k) {
        cout << (rbt.find_by_order(k - 1)->first - delta) << endl;
      } else {
        cout << "-1" << endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}