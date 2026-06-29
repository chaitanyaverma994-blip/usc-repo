#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = -4e18;
struct Edge {
    int u, v, w;
};
signed main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> e(m);
    vector<vector<int>> rev(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        rev[e[i].v].push_back(e[i].u);
    }
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 1; i < n; i++)
        for (auto x : e)
            if (dist[x.u] != INF)
                dist[x.v] = max(dist[x.v], dist[x.u] + x.w);
    vector<int> vis(n + 1);
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : rev[u])
            if (!vis[v]) vis[v] = 1, q.push(v);
    }
    for (auto x : e)
        if (dist[x.u] != INF && dist[x.v] < dist[x.u] + x.w && vis[x.v]) {
            cout << "INFINITE PROFIT";
            return 0;
        }
    if (dist[n] == INF) cout << "UNREACHABLE";
    else cout << dist[n];
}