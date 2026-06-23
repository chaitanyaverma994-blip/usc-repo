#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = N - K; i < N; i++) {
        cout << arr[i];
        if (i < N - 1) cout << " ";
    }

    return 0;
}