#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
typedef __gnu_pbds::tree<pll, __gnu_pbds::null_type, std::less<pll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    RbTree;
struct Node {
  ll l, r;
  RbTree tree;
};
int main() { return 0; }