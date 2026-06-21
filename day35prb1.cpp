#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long prefixSum = 0;
    long long eligible = 0;
    int i = 0;
    while (i < N) {
        int j = i;
        while (j < N && a[j] == a[i]) {
            j++;
        }
        int freq = j - i;
        if (prefixSum >= K) {
            eligible += freq;
        }
        prefixSum += a[i] * 1LL * freq;
        i = j;
    }
    cout << eligible << endl;
    return 0;
}