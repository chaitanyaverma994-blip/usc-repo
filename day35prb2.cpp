#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long X;
    cin >> N >> X;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    set<long long> seen;
    set<pair<long long, long long>> uniquePairs;

    for (int i = 0; i < N; i++) {
        long long complement = X - a[i];

        if (seen.count(complement)) {
            uniquePairs.insert({min(a[i], complement), max(a[i], complement)});
        }

        seen.insert(a[i]);
    }

    cout << uniquePairs.size() << endl;

    return 0;
}