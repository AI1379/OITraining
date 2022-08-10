// https://www.luogu.com.cn/problem/P3369
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define ll long long
namespace __gnu_pbds {
  namespace detail {
    template<>
    class splay_tree_set<ll,
            null_type,
            less<ll>,
            tree_order_statistics_node_update<node_iterator,
                          node_const_iterator,
                          less<ll>,
                          std::allocator<ll>>,
            std::allocator<ll>> {
     public:
      void doSplay(node_iterator it) {
        this->splay(it);
      }
    };
  }
}

int main() {
  return 0;
}
