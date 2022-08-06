#include <iostream>
#include <set>
using namespace std;
#define ll long long
int main() {
  set<ll> st{1, 3, 2, 4, 5, 2};
  for (set<ll>::iterator it = st.begin(); it != st.end(); ++it) {
    cout << (*it) << ' ';
  }
  cout << endl;
  multiset<ll> mst{1, 3, 2, 4, 5, 2};
  for (multiset<ll>::iterator it = mst.begin(); it != mst.end(); ++it) {
    cout << (*it) << ' ';
  }
  cout << endl;
  auto it = mst.find(2);
  ++it;
  cout << (*it) << endl;
  ++it;
  cout << (*it) << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}