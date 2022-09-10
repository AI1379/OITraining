// https://www.luogu.com.cn/problem/P3369
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
__gnu_pbds::tree<pll, __gnu_pbds::null_type, std::less<pll>,
                  __gnu_pbds::rb_tree_tag,
                //  __gnu_pbds::splay_tree_tag,
                 __gnu_pbds::tree_order_statistics_node_update>
    rbt;
ll n;
int main() {
  ll opt, k;
  decltype(rbt)::point_iterator ptr;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> opt >> k;
    switch (opt) {
    case 1:
      rbt.insert(make_pair(k, i));
      break;
    case 2:
      rbt.erase(rbt.lower_bound(make_pair(k, 0)));
      break;
    case 3:
      cout << rbt.order_of_key(make_pair(k, 0)) + 1 << endl;
      break;
    case 4:
      cout << (rbt.find_by_order(k - 1)->first) << endl;
      break;
    case 5:
      ptr = rbt.lower_bound(make_pair(k, 0));
      --ptr;
      cout << (ptr->first) << endl;
      break;
    case 6:
      ptr = rbt.upper_bound(make_pair(k, INF));
      cout << (ptr->first) << endl;
      break;
    }
  }
#ifdef VSCODE
  system("pause");
#endif

  return 0;
}
