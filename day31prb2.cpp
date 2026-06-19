#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    stack<int> st, mn;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "PUSH") {
            int x;
            cin >> x;

            st.push(x);

            if (mn.empty() || x <= mn.top()) {
                mn.push(x);
            }
        }
        else if (op == "POP") {
            if (!st.empty()) {
                if (st.top() == mn.top()) {
                    mn.pop();
                }
                st.pop();
            }
        }
        else if (op == "MIN") {
            if (st.empty()) {
                cout << -1 << "\n";
            } else {
                cout << mn.top() << "\n";
            }
        }
    }

    return 0;
}