#include <cstdio>
#include <cmath>
#define ll long long
const ll MAXN = 100010;
const ll MAXT = MAXN << 1;
const ll MAXC = 30;
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
    for (ll i = 0; i < n; i++) {
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
  void getEuler(Node* cur) {
    euler[cur->pos = now++] = cur;
    for (int i = 0; i < 2; ++i) {
      if (cur->son[i] != nullptr) {
        cur->son[i]->dep = cur->dep + 1;
        getEuler(cur->son[i]);
        euler[now++] = cur;
      }
    }
    return;
  }
}
namespace STBlock {
  using Cartesian::Node;
  static Node* st[MAXC][MAXN];
  static ll b, c;
  Node* minDep(Node* lhs, Node* rhs) {
    return lhs->dep < rhs->dep ? lhs : rhs;
  }
  void init() {
    b = (ll)(ceil(log2(Cartesian::now) / 2));
    c = Cartesian::now / b;
    for (ll i = 0; i < c; ++i) {
      st[0][i] = Cartesian::euler[i * b];
      for (ll j = 1; j < b; ++j) {
        st[0][i] = minDep(st[0][i], Cartesian::euler[i * b + j]);
      }
    }
    for (ll i = 1, l = 2; l <= c; ++i, l <<= 1) {
      for (ll j = 0; j + l <= c; ++j) {
        st[i][j] = minDep(st[i - 1][j], st[i - 1][j + (l >> 1)]);
      }
    }
  }
  Node* query(ll l, ll r) {
    static ll g;
    g = log2n[r - l + 1];
    return minDep(st[g][l], st[g][r - (1 << g) + 1]);
  }
}
namespace InBlocks {
  ll diff[MAXN];
  ll pos[MAXT];
  using STBlock::c;
  using STBlock::b;
  using Cartesian::euler;
  using Cartesian::Node;
  static ll t;
  void init() {
    t = Cartesian::now;
    for (ll i = 0; i <= c; ++i) {
      for (ll j = 1; j < b && i * b + j < t; ++j) {
        if (euler[i * b + j]->dep < euler[i * b + j - 1]->dep) {
          diff[i] |= (1 << (j - 1));
        }
      }
    }
    static ll cur = 0, min = 0;
    for (ll sta = 0; sta < (1 << (b - 1)); ++sta) {
      cur = 0;
      min = 0;
      for (ll i = 1; i < b; ++i) {
        cur += ((sta >> (i - 1)) & 1) ? -1 : 1;
        if (cur < min) {
          min = cur;
          pos[sta] = i;
        }
      }
    }
  }
  Node * query(ll l, ll r) {
    static ll p;
    p = l / b;
    static ll state;
    state = ((diff[p] >> (l - p * b)) & ((1 << (r - l)) - 1));
    return euler[l + pos[state]];
  }
}
void init() {
  log2n[1] = 0;
  for (ll i = 2; i <= n; ++i) {
    log2n[i] = log2n[i / 2] + 1;
  }
  Cartesian::build();
  Cartesian::getEuler(Cartesian::root);
  STBlock::init();
  InBlocks::init();
}
Cartesian::Node* queryNode(ll l, ll r) {
  if (l > r)
    return queryNode(r, l);
  static ll pl, pr;
  static Cartesian::Node * res;
  static ll b = STBlock::b;
  pl = l / STBlock::b;
  pr = r / STBlock::b;
  if (pl == pr) {
    return InBlocks::query(l, r);
  }
  res = STBlock::minDep(InBlocks::query(l, pl * b + b - 1),
                        InBlocks::query(pr * b, r));
  if (pl + 1 < pr) {
    res = STBlock::minDep(res, STBlock::query(pl + 1, pr - 1));
  }
  return res;
}
ll query(ll l, ll r) {
  return queryNode(Cartesian::cartesian[l - 1].pos, Cartesian::cartesian[r - 1].pos)->val;
}
int main() {
  using namespace std;
  ll l, r;
  scanf("%lld%lld", &n, &m);
  for (ll i = 0; i < n; i++) {
    scanf("%lld", original + i);
  }
  init();
  while (m--) {
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", query(l, r));
  }
  return 0;
}
