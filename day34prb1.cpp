#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    if (fresh == 0) {
        cout << 0 << endl;
        return 0;
    }
    int minutes = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty() && fresh > 0) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                    grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
        minutes++;
    }
    if (fresh > 0)
        cout << -1 << endl;
    else
        cout << minutes << endl;
    return 0;
}