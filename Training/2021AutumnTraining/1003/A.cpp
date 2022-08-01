#include <bits/stdc++.h>
using namespace std;
struct person {
  int val;
  int pos;
  person(int b, int c) : val(b), pos(c) {}
};
int n, m;
vector<person> lst[26];
bool sorted[26];
string name[100010];
bool cmp(person a, person b) {
  return a.val == b.val ? a.pos < b.pos : a.val > b.val;
}
int main() {
  string s;
  char q;
  int val;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s >> val;
    lst[s[s.length() - 1] - 'a'].push_back(person(val, i));
    name[i] = s;
  }
  while (m--) {
    cin >> q >> val;
    if (lst[q - 'a'].size() < val) {
      cout << "Orz YYR tql" << endl;
      continue;
    }
    if (!sorted[q - 'a']) {
      sorted[q - 'a'] = true;
      sort(lst[q - 'a'].begin(), lst[q - 'a'].end(), cmp);
    }
    cout << name[lst[q - 'a'][val - 1].pos] << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}