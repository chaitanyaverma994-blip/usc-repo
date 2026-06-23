#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> marks(N);
    for (int i = 0; i < N; i++) {
        cin >> marks[i];
    }

    sort(marks.begin(), marks.end(), greater<int>());

    int Q;
    cin >> Q;

    while (Q--) {
        int score;
        cin >> score;

        auto it = find(marks.begin(), marks.end(), score);

        if (it != marks.end()) {
            cout << "Rank " << (it - marks.begin() + 1) << endl;
        } else {
            cout << "No Rank" << endl;
        }
    }

    return 0;
}