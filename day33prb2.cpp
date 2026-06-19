#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    deque<int> dq;

    for (int i = 0; i < N; i++) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Print maximum for each complete window
        if (i >= K - 1) {
            cout << arr[dq.front()];
            if (i != N - 1) cout << " ";
        }
    }

    return 0;
}