#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    unordered_set<int> s;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        s.insert(nums[i]);
    }

    int longest = 0;

    for (int num : s) {
        // Check if it is the start of a sequence
        if (s.find(num - 1) == s.end()) {
            int currentNum = num;
            int length = 1;

            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    cout << longest;

    return 0;
}