#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    int X;
    cin >> X;

    int low = 0, high = N * M - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / M;
        int col = mid % M;

        if (matrix[row][col] == X) {
            found = true;
            break;
        }
        else if (matrix[row][col] < X) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << (found ? "FOUND" : "NOT FOUND");

    return 0;
}