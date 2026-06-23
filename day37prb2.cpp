#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    unordered_map<long long, long long> mp;
    mp[0] = 1;

    long long prefixSum = 0;
    long long count = 0;

    for (int i = 0; i < N; i++) {
        prefixSum += arr[i];

        if (mp.find(prefixSum - K) != mp.end()) {
            count += mp[prefixSum - K];
        }

        mp[prefixSum]++;
    }

    cout << count;

    return 0;
}