#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (color[i] != 0) continue;
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == 0) {
                    color[v] = 3 - color[u]; 
                    q.push(v);
                } else if (color[v] == color[u]) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= N; i++) {
        cout << color[i];
        if (i < N) cout << " ";
    }
    cout << "\n";
    return 0;
}