#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> treasure(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> treasure[i];
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(N + 1, false);
    queue<pair<int, int>> q; // {node, level}
    q.push({1, 0});
    vis[1] = true;
    long long ans = 0;
    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        if (level % 2 == 0)
            ans += treasure[node];
        for (int child : adj[node]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push({child, level + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}