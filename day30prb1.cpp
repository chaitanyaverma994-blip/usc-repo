#include <bits/stdc++.h>
using namespace std;

int p(char c){
    return (c=='+'||c=='-') ? 1 : (c=='*'||c=='/') ? 2 : 0;
}

int main() {
    string s, ans;
    cin >> s;
    stack<char> st;

    for(char c : s){
        if(isalpha(c)) ans += c;
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(st.top() != '(') ans += st.top(), st.pop();
            st.pop();
        }
        else{
            while(!st.empty() && p(st.top()) >= p(c))
                ans += st.top(), st.pop();
            st.push(c);
        }
    }

    while(!st.empty()) ans += st.top(), st.pop();
    cout << ans;
}