#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    unordered_map<char, int> need;

    for (char c : T)
        need[c]++;

    int required = need.size();
    int formed = 0;

    unordered_map<char, int> window;

    int left = 0, minLen = INT_MAX, start = 0;

    for (int right = 0; right < S.size(); right++) {
        char c = S[right];
        window[c]++;

        if (need.count(c) && window[c] == need[c])
            formed++;

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            char ch = S[left];
            window[ch]--;

            if (need.count(ch) && window[ch] < need[ch])
                formed--;

            left++;
        }
    }

    if (minLen == INT_MAX)
        cout << -1;
    else
        cout << S.substr(start, minLen);

    return 0;
}