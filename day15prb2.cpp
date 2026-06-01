#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int weights[1000];

    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    sort(weights, weights + N);

    int maxLoad = 0;

    for (int i = 0; i < N / 2; i++) {
        int load = weights[i] + weights[N - 1 - i];
        if (load > maxLoad) {
            maxLoad = load;
        }
    }

    cout << maxLoad << endl;

}