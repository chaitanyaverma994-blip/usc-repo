#include <bits/stdc++.h>
using namespace std;
int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> mat(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
    bool first = true;
    for (int d = 0; d <= M + N - 2; d++) {
        if (d % 2 == 0) {
            // Bottom to top
            int r = min(d, M - 1);
            int c = d - r;
            while (r >= 0 && c < N) {
                if (!first) cout << " ";
                cout << mat[r][c];
                first = false;
                r--;
                c++;
            }
        } else {
            // Top to bottom
            int c = min(d, N - 1);
            int r = d - c;
            while (c >= 0 && r < M) {
                if (!first) cout << " ";
                cout << mat[r][c];
                first = false;
                r++;
                c--;
            }
        }
    }

    return 0;
}