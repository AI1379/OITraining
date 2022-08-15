#include <bits/stdc++.h>
#include <ostream>
#define private public
#define protected public
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#undef private
#undef protected
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
ll n, m;
ll l, r;
struct SplayMetadata {
  ll val, size;
  bool tag;
};
template <typename Node_CItr, typename Node_Itr, typename Cmp_Fn,
          typename Alloc>
struct SplayTreeUpdate {
public:
  using metadata_type = SplayMetadata;
  void operator()(Node_Itr u, Node_CItr end_it) {
    if (u != end_it) {
      auto l = u.get_l_child(), r = u.get_r_child();
      ll lsize = 0, rsize = 0;
      auto tag = u.get_metadata().tag;
      if (l != end_it) {
        if (tag) {
          const_cast<bool &>(l.get_metadata().tag) ^= 1;
        }
        lsize = l.get_metadata().size;
      }
      if (u.get_r_child() != end_it) {
        if (tag) {
          const_cast<bool &>(r.get_metadata().tag) ^= 1;
        }
        rsize = r.get_metadata().size;
      }
      if (tag) {
        swap(u.m_p_nd->m_p_left, u.m_p_nd->m_p_right);
        const_cast<bool &>(u.get_metadata().tag) = false;
      }
      const_cast<ll &>(u.get_metadata().size) = lsize + rsize + 1;
    }
  }
  virtual Node_CItr node_begin() const = 0;
  virtual Node_CItr node_end() const = 0;
  void pushdown(Node_Itr u) { operator()(u, node_end()); }
  Node_Itr find_by_order(ll x) {
    Node_Itr u = node_begin();
    while (true) {
      pushdown(u);
      if (x <= u.get_l_child().get_metadata().size) {
        u = u.get_l_child();
      } else {
        x -= u.get_l_child().get_metadata().size + 1;
        if (!x) {
          return u;
        }
        u = u.get_r_child();
      }
    }
  }
};
using SplayTree = __gnu_pbds::tree<ll, __gnu_pbds::null_type, std::less<ll>,
                                   __gnu_pbds::splay_tree_tag, SplayTreeUpdate,
                                   std::allocator<char>>;
// template <>
// SplayTree::node_iterator SplayTree::node_update::find_by_order(ll x) {
//   using Node_Itr = SplayTree::node_iterator;
//   Node_Itr u = node_begin();
//   while (true) {
//     pushdown(u);
//     if (x <= u.get_l_child().get_metadata().size) {
//       u = u.get_l_child();
//     } else {
//       x -= u.get_l_child().get_metadata().size + 1;
//       if (!x) {
//         return u;
//       }
//       u = u.get_r_child();
//     }
//   }
// }
SplayTree tree;
void prevOrder(decltype(tree.m_p_head) cur, ll dep) {
  if (!cur)
    return;
  cout << cur->m_value << ' ' << cur->get_metadata().val << ' ' << dep << endl;
  prevOrder(cur->m_p_left, dep + 1);
  prevOrder(cur->m_p_right, dep + 1);
}
void middleOrder(decltype(tree.m_p_head) cur, ll dep) {
  if (!cur)
    return;
  middleOrder(cur->m_p_left, dep + 1);
  cout << cur->m_value << ' ' << cur->get_metadata().val << ' ' << dep << endl;
  middleOrder(cur->m_p_right, dep + 1);
}
void print() {
  cout << "=====================" << endl;
  cout << tree.size() << endl;
  cout << "Prev:" << endl;
  prevOrder(tree.node_begin().m_p_nd, 1);
  cout << "============" << endl << "Middle:" << endl;
  middleOrder(tree.node_begin().m_p_nd, 1);
  cout << "=========================" << endl;
}
void reverse(ll l, ll r) {
  auto l_p_nd = tree.find_by_order(l - 1).m_p_nd;
  auto r_p_nd = tree.find_by_order(r + 1).m_p_nd;
  cout << l_p_nd->m_metadata.val << ' ' << l_p_nd->m_metadata.size << endl;
  cout << r_p_nd->m_metadata.val << ' ' << r_p_nd->m_metadata.size << endl;
  print();
  // auto l_p_nd = tree.find(l - 1).m_p_nd, r_p_nd = tree.find(r + 1).m_p_nd;
  tree.splay(l_p_nd);
  print();
  auto tmp = tree.m_p_head;
  tree.m_p_head = l_p_nd;
  tree.splay(r_p_nd);
  tree.m_p_head = tmp;
  print();
  tree.node_begin().m_p_nd->m_p_right->m_p_left->m_metadata.tag ^= 1;
  // const_cast<bool &>(
  // tree.node_begin().get_r_child().get_l_child().get_metadata().second) ^=
  // 1;
}

void dfs(SplayTree::node_iterator u) {
  tree.pushdown(u);
  if (u.get_l_child() != tree.node_end()) {
    dfs(u.get_l_child());
  }
  if (u.get_metadata().val != -INF && u.get_metadata().val != INF) {
    cout << u.get_metadata().val << ' ';
  }
  if (u.get_r_child() != tree.node_end()) {
    dfs(u.get_r_child());
  }
}

int main() {
  SplayTree::iterator it;
  cin >> n >> m;
  it = tree.insert(1).first;
  it.m_p_nd->m_metadata.val = -INF;
  it = tree.insert(n + 2).first;
  it.m_p_nd->m_metadata.val = INF;
  for (int i = 1; i <= n; i++) {
    it = tree.insert(i + 1).first;
    it.m_p_nd->m_metadata.val = i;
  }
  for (auto it = tree.begin(); it != tree.end(); ++it) {
    cout << it.m_p_nd->m_value << endl;
    if (it.m_p_nd->m_p_left)
      cout << "LEFT: " << it.m_p_nd->m_p_left->m_value << endl;
    if (it.m_p_nd->m_p_right)
      cout << "RIGHT: " << it.m_p_nd->m_p_right->m_value << endl;
  }
  print();
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r;
    reverse(l + 1, r + 1);
  }
  dfs(tree.node_begin());
  // dfs(tree.node_begin().m_p_nd);
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}