#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> ids(N);
    for (int i = 0; i < N; i++) {
        cin >> ids[i];
    }

    int K;
    cin >> K;

    int idx = 0;

    while (ids.size() > 1) {
        idx = (idx + K - 1) % ids.size();
        ids.erase(ids.begin() + idx);
    }

    cout << ids[0] << endl;

}