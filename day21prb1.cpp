#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        // Skip empty lines if present
        if (line.empty()) {
            i--;
            continue;
        }

        stringstream ss(line);
        int x;

        while (ss >> x) {
            pq.push(x);
        }
    }

    bool first = true;
    while (!pq.empty()) {
        if (!first) cout << " ";
        cout << pq.top();
        pq.pop();
        first = false;
    }

    return 0;
}