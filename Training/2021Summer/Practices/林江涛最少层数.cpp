#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
const int MAXM = 100010;
int n, m;
vector<int>graph[MAXN];
int deg[MAXN];
queue<int>q;
int f[MAXN];
int main() {
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        deg[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            deg[graph[x][i]]--;
            if (deg[graph[x][i]] == 0) {
                q.push(graph[x][i]);
            }
            f[graph[x][i]] = max(f[graph[x][i]], f[x] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans + 1 << endl;
    return 0;
}
