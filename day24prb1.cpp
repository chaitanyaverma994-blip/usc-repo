#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long W;
    cin >> N >> W;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int left = 0, maxLen = 0;
    long long sum = 0;

    for (int right = 0; right < N; right++) {
        sum += a[right];

        while (sum > W) {
            sum -= a[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << endl;

    return 0;
}