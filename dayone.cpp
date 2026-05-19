#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cout << "enter the total number of marks" << endl;
    cin >> N;

    vector<int> marks(N);
    cout << "enter the marks" << endl;
    for (int i = 0; i < N; i++) {
        cin >> marks[i];
    }

    unordered_set<int> s;
    bool duplicate = false;
    for (int i = 0; i < N; i++) {
        if (s.count(marks[i])) {
            duplicate = true;
            break;
        }
        s.insert(marks[i]);
    }
    cout << "the result is" << endl;
    if (duplicate)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}