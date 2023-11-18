#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct MemDetail {
  string name;
  string tpname;
  ll offset;
};
struct Type {
  string name;
  map<string, MemDetail *> members;
  map<ll, MemDetail *> memmap;
  ll align;
  ll size;
};
typedef MemDetail Object;
map<string, Type *> typemap;
ll memcursor;
map<ll, Object *> pool;
map<string, Object *> objmap;
bool isbasictype(const string &s) {
  return s == "byte" || s == "short" || s == "int" || s == "long";
}
ll basicsize(const string &s) {
  if (s == "byte")
    return 1;
  if (s == "short")
    return 2;
  if (s == "int")
    return 4;
  if (s == "long")
    return 8;
  return -1;
}
Type *constructType() {
  string s, n;
  ll k;
  auto res = new Type();
  cin >> res->name >> k;
  ll cur = 0, mbsize, mbalign;
  for (int i = 0; i < k; ++i) {
    cin >> s >> n;
    MemDetail *d = new MemDetail();
    d->tpname = s;
    d->name = n;
    mbsize = mbalign = basicsize(s);
    if (mbsize == -1) {
      mbsize = typemap[s]->size;
      mbalign = typemap[s]->align;
    }
    res->align = max(res->align, mbalign);
    if (cur % mbalign != 0)
      cur = mbalign * (cur / mbalign + 1);
    d->offset = cur;
    res->memmap[cur] = res->members[n] = d;
    cur += mbsize;
  }
  if (cur % res->align != 0)
    cur = res->align * (cur / res->align + 1);
  res->size = cur;
  typemap[res->name] = res;
  cout << res->size << ' ' << res->align << endl;
  return res;
}
Object *constructObject() {
  ll align, size;
  Object *res = new Object();
  cin >> res->tpname >> res->name;
  if (isbasictype(res->tpname)) {
    size = align = basicsize(res->tpname);
  } else {
    align = typemap[res->tpname]->align;
    size = typemap[res->tpname]->size;
  }
  if (memcursor % align != 0)
    memcursor = align * (memcursor / align + 1);
  res->offset = memcursor;
  objmap[res->name] = pool[memcursor] = res;
  memcursor += size;
  cout << res->offset << endl;
  return res;
}
ll queryoffset(const string &s) {
  string cur;
  ll res = 0;
  Object *p = nullptr;
  for (auto c : s) {
    if (c == '.') {
      if (p == nullptr) {
        p = objmap[cur];
        res = p->offset;
      } else {
        p = typemap[p->tpname]->members[cur];
        res += p->offset;
      }
      cur = "";
    } else {
      cur = cur + c;
    }
  }
  if (p == nullptr) {
    p = objmap[cur];
    res = p->offset;
  } else {
    p = typemap[p->tpname]->members[cur];
    res += p->offset;
  }
  return res;
}
string queryvar(ll offset) {
  string res;
  if (offset >= memcursor || offset < 0 || pool.empty())
    return "ERR";
  auto cur = pool.lower_bound(offset);
  if (cur->first != offset)
    --cur;
  res = cur->second->name;
  if (isbasictype(cur->second->tpname)) {
    if (cur->second->offset <= offset &&
        offset < cur->second->offset + basicsize(cur->second->tpname))
      return res;
    else
      return "ERR";
  }
  while (cur->first != offset) {
    offset -= cur->first;
    cur = typemap[cur->second->tpname]->memmap.lower_bound(offset);
    if (cur->first != offset)
      --cur;
    res = res + "." + cur->second->name;
    if (isbasictype(cur->second->tpname)) {
      if (cur->second->offset <= offset &&
          offset < cur->second->offset + basicsize(cur->second->tpname))
        break;
      else
        return "ERR";
    }
  }
  return res;
}
ll n;
int main() {
  ll op, u;
  string s;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> op;
    if (op == 1) {
      constructType();
    } else if (op == 2) {
      constructObject();
    } else if (op == 3) {
      cin >> s;
      cout << queryoffset(s) << endl;
    } else if (op == 4) {
      cin >> u;
      cout << queryvar(u) << endl;
    }
  }
  return 0;
}