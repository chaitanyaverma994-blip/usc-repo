#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> inD, outD;
unordered_map<string, vector<string>> g;
unordered_set<string> vis;
void dfs(string u) {
    vis.insert(u);
    for (auto v : g[u])
        if (!vis.count(v)) dfs(v);
}
int main() {
    int P;
    cin >> P;
    set<string> nodes;
    for (int i = 0; i < P; i++) {
        string u, v;
        cin >> u >> v;
        outD[u]++, inD[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
        nodes.insert(u);
        nodes.insert(v);
    }
    int s = 0, e = 0;
    for (auto x : nodes) {
        int d = outD[x] - inD[x];
        if (d == 1) s++;
        else if (d == -1) e++;
        else if (d != 0) {
            cout << "ASSEMBLY IMPOSSIBLE";
            return 0;
        }
    }
    dfs(*nodes.begin());
    for (auto x : nodes)
        if (!vis.count(x)) {
            cout << "ASSEMBLY IMPOSSIBLE";
            return 0;
        }
    if ((s == 1 && e == 1) || (s == 0 && e == 0))
        cout << "ASSEMBLY POSSIBLE";
    else
        cout << "ASSEMBLY IMPOSSIBLE";
}