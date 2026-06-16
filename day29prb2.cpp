#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string res = "";

    for (char ch : s) {
        if (!res.empty() && res.back() == ch)
            res.pop_back();
        else
            res.push_back(ch);
    }

    if (res.empty())
        cout << "EMPTY";
    else
        cout << res;

    return 0;
}