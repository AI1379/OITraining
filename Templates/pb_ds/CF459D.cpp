#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
template <typename Node_CItr, typename Node_Itr, typename Cmp_Fn,
          typename Alloc>
struct NodeUpdateSize
    : public __gnu_pbds::tree_order_statistics_node_update<Node_CItr, Node_Itr,
                                                           Cmp_Fn, Alloc> {
public:
  typedef ll metadata_type;
  void operator()(Node_Itr it, Node_CItr end_it) {
    Node_Itr l = it.get_l_child();
    Node_Itr r = it.get_r_child();
    int left = 0, right = 0;
    if (l != end_it)
      left = l.get_metadata();
    if (r != end_it)
      right = r.get_metadata();
    const_cast<ll &>(it.get_metadata()) = left + right + 1;
  }
};
ll n;
__gnu_pbds::tree<pll, __gnu_pbds::null_type, less<pll>, __gnu_pbds::rb_tree_tag,
                 NodeUpdateSize>
    rbt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  map<int, int> cnt[2];
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> pre(n), suf(n);
  for (int i = 0; i < n; i++) {
    pre[i] = cnt[0][a[i]]++;
    suf[n - i - 1] = cnt[1][a[n - i - 1]]++;
  }
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    rbt.insert({pre[i - 1], i - 1});
    ans += i - rbt.order_of_key({suf[i], i});
  }
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}