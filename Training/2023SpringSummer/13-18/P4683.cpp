#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll MAXN = 25010;
ll n;
ll trie[MAXN * 20][26], tot = 0;
bool lst[MAXN * 20], tag[MAXN * 20];
string l;
ll ans = 0;
stringstream ss;
void ins(const string &s) {
  ll cur = 1;
  for (auto c : s) {
    if (!trie[cur][c - 'a'])
      trie[cur][c - 'a'] = ++tot;
    cur = trie[cur][c - 'a'];
  }
  lst[cur] = true;
}
void mark() {
  ll cur = 1;
  for (auto c : l) {
    tag[trie[cur][c - 'a']] = true;
    cur = trie[cur][c - 'a'];
  }
}
void dfs(ll cur) {
  ll p = -1;
  if (lst[cur]) {
    ++ans;
    ss << "P" << endl;
  }
  for (int i = 0; i < 26; ++i) {
    if (!tag[trie[cur][i]] && trie[cur][i]) {
      ss << (char)('a' + i) << endl;
      dfs(trie[cur][i]);
      ss << '-' << endl;
      ans += 2;
    } else if (tag[trie[cur][i]]) {
      p = i;
    }
  }
  if (p != -1) {
    ss << (char)('a' + p) << endl;
    ++ans;
    dfs(trie[cur][p]);
  }
}
int main() {
  string s;
  cin >> n;
  tot = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    ins(s);
    if (l.length() < s.length())
      l = s;
  }
  mark();
  dfs(1);
  cout << ans << endl;
  cout << ss.str();
  return 0;
}