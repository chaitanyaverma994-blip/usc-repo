#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    Node *l, *r;
    Node(int x) : v(x), l(NULL), r(NULL) {}
};

bool leaf(Node *x) { return x && !x->l && !x->r; }

void left(Node *x, vector<int> &a) {
    for (x = x->l; x; x = x->l ? x->l : x->r)
        if (!leaf(x)) a.push_back(x->v);
}

void leaves(Node *x, vector<int> &a) {
    if (!x) return;
    if (leaf(x)) { a.push_back(x->v); return; }
    leaves(x->l, a);
    leaves(x->r, a);
}

void right(Node *x, vector<int> &a) {
    vector<int> t;
    for (x = x->r; x; x = x->r ? x->r : x->l)
        if (!leaf(x)) t.push_back(x->v);
    for (int i = t.size() - 1; i >= 0; i--) a.push_back(t[i]);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    if (n == 0 || a[0] == -1) return 0;

    Node *root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);

    for (int i = 1; !q.empty() && i < n;) {
        Node *cur = q.front(); q.pop();
        if (i < n && a[i] != -1) q.push(cur->l = new Node(a[i]));
        i++;
        if (i < n && a[i] != -1) q.push(cur->r = new Node(a[i]));
        i++;
    }

    vector<int> ans;
    if (!leaf(root)) ans.push_back(root->v);
    left(root, ans);
    leaves(root, ans);
    right(root, ans);

    for (int x : ans) cout << x << " ";
}