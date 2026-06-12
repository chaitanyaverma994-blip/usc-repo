#include <bits/stdc++.h>
using namespace std;

long long moves = 0;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move plate 1 from " << source << " to " << destination << "\n";
        moves++;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move plate " << n << " from " << source << " to " << destination << "\n";
    moves++;

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int N;
    cin >> N;

    towerOfHanoi(N, 'A', 'B', 'C');

    cout << "Total Moves = " << moves;

    return 0;
}