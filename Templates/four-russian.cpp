#include <iostream>
#include <cmath>
#define ll long long
const ll MAXN = 100010;
const ll MAXT = MAXN << 1;
static ll n, m;
static ll original[MAXN];
static ll log2n[MAXN];
namespace Cartesian {
  struct Node {
    ll val;
    ll pos, dep;
    Node *son[2];
  };
  static Node* root;
  static Node cartesian[MAXN];
  static Node* stk[MAXN];
  static Node* euler[MAXN * 2];
  static ll top = 0, now = 0;
  void build() {
    for (int i = 1; i <= n; i++) {
      cartesian[i].val = original[i];
      cartesian[i].son[0] = cartesian[i].son[1] = nullptr;
      while (top && stk[top]->val < original[i]) {
        cartesian[i].son[0] = stk[top--];
      }
      if (top) {
        stk[top]->son[1] = &cartesian[i];
      }
      stk[++top] = &cartesian[i];
    }
    root = stk[1];
    return;
  }
  void getEuler(Node* cur, Node* pa) {
    if (cur == nullptr) {
      return;
    }
    if (pa == nullptr) {
      cur->dep = 1;
    } else {
      cur->dep = pa->dep + 1;
    }
    euler[now] = cur;
    cur->pos = now++;
    if (cur->son[0] != nullptr) {
      getEuler(cur->son[0], cur);
      euler[now++] = cur;
    }
    if (cur->son[1] != nullptr) {
      getEuler(cur->son[1], cur);
      euler[now++] = cur;
    }
    return;
  }
}
namespace STBlock {
  using Cartesian::Node;
  static Node* st[20][MAXN];
  static ll block_size, block_num;
  Node* minDep(Node* lhs, Node* rhs) {
    return lhs->dep < rhs->dep ? lhs : rhs;
  }
  void init() {
    block_size = (ll)(ceil(log2(Cartesian::now) / 2));
//    block_size = log2n[Cartesian::now] / 2;
    block_num = Cartesian::now / block_size;
    for (int i = 0; i < block_num; ++i) {
      st[0][i] = Cartesian::euler[i * block_size];
      for (int j = 1; j < block_size; ++j) {
        st[0][i] = minDep(st[0][i], Cartesian::euler[i * block_size + j]);
      }
    }
    for (int i = 1; (1 << i) <= block_num; ++i) {
      for (int j = 0; j + (1 << i) <= block_num; ++j) {
        st[i][j] = minDep(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  Node* query(ll l, ll r) {
    static ll g = log2n[r - l + 1];
    return minDep(st[g][l], st[g][r - (1 << g) + 1]);
  }
}
namespace InBlocks {
  ll diff[20];
  ll pos[MAXN];
  using STBlock::block_num;
  using STBlock::block_size;
  using Cartesian::euler;
  using Cartesian::Node;
  ll t;
  void init() {
    t = Cartesian::now;
    for (int i = 1; i <= block_num; ++i) {
      for (int j = 1; j < block_size && i * block_size + j < t; ++j) {
        if (euler[i * block_size + j]->dep < euler[i * block_size + j - 1]->dep) {
          diff[i] |= (1 << (j - 1));
        }
      }
    }
    static ll cur = 0, min = 0;
    for (int sta = 0; sta < (1 << (block_size - 1)); ++sta) {
      cur = 0;
      min = 0;
      for (int i = 1; i < block_size; ++i) {
        cur += ((sta >> (i - 1)) & 1) ? 1 : -1;
        if (cur < min) {
          min = cur;
          pos[sta] = i;
        }
      }
    }
  }
  Node * query(ll l, ll r) {
    static ll block_pos = l / block_size;
    static ll state = ((diff[block_pos] >> (l - block_pos * block_size))
                       & ((1 << (r - l)) - 1));
    return euler[l + pos[state]];
  }
}
void init() {
  log2n[1] = 0;
  for (int i = 2; i < MAXN; ++i) {
    log2n[i] = log2n[i / 2] + 1;
  }
  Cartesian::build();
  Cartesian::getEuler(Cartesian::root, nullptr);
  for (int i = 0; i < Cartesian::now; ++i) {
    std::cout << Cartesian::euler[i]->val << ' ';
  }
  std::cout << std::endl;
  for (int i = 0; i < Cartesian::now; ++i) {
    std::cout << Cartesian::euler[i]->dep << ' ';
  }
  std::cout << std::endl;
  STBlock::init();
  InBlocks::init();
}
Cartesian::Node* queryNode(ll l, ll r) {
  static ll pl, pr;
  static Cartesian::Node * res;
  static ll b = STBlock::block_size;
  pl = l / STBlock::block_size;
  pr = r / STBlock::block_size;
  if (pl == pr) {
    std::cout << "Same block" << std::endl;
    return InBlocks::query(l, r);
  }
  res = STBlock::minDep(InBlocks::query(l, pl * b + b - 1),
                        InBlocks::query(pr * b, r));
  if (pl + 1 < pr) {
    std::cout << "Neighbour block" << std::endl;
    res = STBlock::minDep(res, STBlock::query(pl + 1, pr - 1));
  }
  return res;
}
ll query(ll l, ll r) {
  std::cout << Cartesian::cartesian[l].pos << ' ' << Cartesian::cartesian[r].pos << std::endl;
  return queryNode(Cartesian::cartesian[l].pos, Cartesian::cartesian[r].pos)->val;
}
int main() {
  using namespace std;
  ll l, r;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> original[i];
  }
  init();
  std::cout << Cartesian::now << ' ' << STBlock::block_size << ' ' << STBlock::block_num << std::endl;
  while (m--) {
    cin >> l >> r;
    cout << query(l, r) << endl;
  }
  return 0;
}
