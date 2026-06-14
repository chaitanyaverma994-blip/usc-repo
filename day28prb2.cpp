#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    queue<int> q;
    while (Q--) {
        string op;
        cin >> op;
        if (op == "REGISTER") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (op == "WITHDRAW") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                q.pop();
            }
        }
        else if (op == "NEXT") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
    }

    return 0;
}