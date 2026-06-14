#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
            st.push(ch);
        } 
        else {
            if (st.empty()) {
                cout << "INVALID";
                return 0;
            }
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{') ||
                (ch == '>' && top == '<')) {
                st.pop();
            } else {
                cout << "INVALID";
                return 0;
            }
        }
    }

    cout << (st.empty() ? "VALID" : "INVALID");

    return 0;
}