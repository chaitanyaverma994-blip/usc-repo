#include <bits/stdc++.h>
using namespace std;

struct Passenger {
    int id;
    int priority;
    int order; // check-in order
};

int main() {
    int N;
    cin >> N;

    vector<Passenger> passengers(N);

    for (int i = 0; i < N; i++) {
        cin >> passengers[i].id >> passengers[i].priority;
        passengers[i].order = i;
    }

    sort(passengers.begin(), passengers.end(), [](const Passenger &a, const Passenger &b) {
        if (a.priority != b.priority)
            return a.priority > b.priority; // higher priority first
        return a.order < b.order; // earlier check-in first
    });

    for (const auto &p : passengers) {
        cout << p.id << "\n";
    }

    return 0;
}