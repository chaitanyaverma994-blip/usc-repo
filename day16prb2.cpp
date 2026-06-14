#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, X;
    cin >> N >> K >> X;

    int a[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= N - K; i++) {
        int sum = 0;
        bool valid = true;

        for (int j = i; j < i + K; j++) {
            sum += a[j];

            if (a[j] == 0) {
                valid = false;
            }
        }

        if (valid && sum >= X) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}