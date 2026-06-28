#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> g[N];
int st[N], en[N], t = 0;
long long a[N], bit[N];
void dfs(int u, int p) {
    st[u] = ++t;
    for (int v : g[u]) if (v != p) dfs(v, u);
    en[u] = t;
}
void upd(int i, long long v) {
    while (i < N) bit[i] += v, i += i & -i;
}
long long sum(int i) {
    long long s = 0;
    while (i) s += bit[i], i -= i & -i;
    return s;
}
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) upd(st[i], a[i]);
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            long long v;
            cin >> v;
            upd(st[x], v - a[x]);
            a[x] = v;
        } else {
            cout << sum(en[x]) - sum(st[x] - 1) << "\n";
        }
    }
}