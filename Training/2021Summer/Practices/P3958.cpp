#include <bits/stdc++.h>
using namespace std;
struct ball {
  long long x, y, z;
};
long long t;
long long n, h, r;
long long fa[1010];
ball balls[1010];

long long fd(long long x) { return fa[x] = (fa[x] == x ? fa[x] : fd(fa[x])); }
void un(long long x, long long y) {
  long long a = fd(x), b = fd(y);
  if (a != b) fa[a] = b;
}
bool judge(ball a, ball b) {
  return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
          (a.z - b.z) * (a.z - b.z)) <= (4 * r * r);
}
void solve() {
  cin >> n >> h >> r;
  vector<long long> bottom, top;
  for (long long i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> balls[i].x >> balls[i].y >> balls[i].z;
    if (balls[i].z <= r) bottom.push_back(i);
    if (balls[i].z >= h - r) top.push_back(i);
    for (long long j = 1; j < i; j++) {
      if (judge(balls[i], balls[j])) {
        un(i, j);
      }
    }
  }
  for (long long i = 0; i < bottom.size(); i++) {
    for (long long j = 0; j < top.size(); j++) {
      if (fd(bottom[i]) == fd(top[j])) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
  return;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
