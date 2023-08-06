#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 1000010;
ll n, m, p, q, curp, curq, cur;
ll tag[MAXN], last[MAXN];
ll ans[MAXN];
priority_queue<pll> heap;
void run() {
  ll l, r;
  for (int i = 1; i <= m; ++i) {
    l = min((i * p + q) % n, (i * q + p) % n);
    r = max((i * p + q) % n, (i * q + p) % n);
    for (int j = l; j <= r; ++j) {
      ans[j] = i;
    }
  }
}
int main() {
  //   cin >> n >> m >> p >> q
  srand(time(NULL));
  while (true) {
    n = 435;
    m = 401;
    p = 18;
    q = 28;
    for (int i = 1; i <= m; ++i) {
      curp = (i * p + q) % n;
      curq = (i * q + p) % n;
      cur = min(curp, curq);
      tag[cur] = i;
      last[cur] = max(curp, curq);
      //   len[cur] = abs(curp - curq) % n;
      if (i == 77)
        cout << i << ' ' << curp << ' ' << curq << ' ' << last[cur] << endl;
    }
    heap.emplace(0, n);
    run();
    for (int i = 0; i < n; ++i) {
      if (107 <= i && i <= 111) {
        cout << i << ' ' << tag[i] << endl;
      }
      while (heap.top().second < i) {
        if (heap.top().first == 77)
          cout << i << endl;
        heap.pop();
      }
      if (tag[i] != 0)
        heap.emplace(tag[i], last[i]);
      if (heap.top().first != ans[i]) {
        cout << "ERROR! " << n << ' ' << m << ' ' << p << ' ' << q << endl;
        cout << i << ' ' << heap.top().first << endl;
        for (int j = 0; j < n; ++j) {
          cout << ans[j] << ' ';
        }
        cout << endl;
        return 1;
      }
      // cout << heap.top().first << ' ';
    }
    cout << "OK" << endl;
    system("clear");
    //   cout << endl;
    n = rand() % 1000 + 10;
    m = rand() % 1000 + 10;
    p = rand() % n;
    q = rand() % n;
    memset(tag, 0, sizeof(tag));
    memset(last, 0, sizeof(last));
    memset(ans, 0, sizeof(ans));
    while (!heap.empty())
      heap.pop();
  }
  return 0;
}
