#include <bits/stdc++.h>
using namespace std;
vector<int> g[25];
bool vis[25];
int n, m;
bool dfs(int u, int cnt) {
    if (cnt == n) return true;
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v] && dfs(v, cnt + 1))
            return true;
    vis[u] = false;
    return false;
}
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i, 1)) {
            cout << "MISSION POSSIBLE";
            return 0;
        }
    }
    cout << "MISSION FAILED";
}