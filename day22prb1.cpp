#include <bits/stdc++.h>
using namespace std;

void solve(int x, int y, vector<vector<int>> &maze, int n,
           vector<vector<int>> &vis, string path,
           vector<string> &ans) {

    // Destination reached
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    // Down
    if (x + 1 < n && maze[x + 1][y] == 1 && !vis[x + 1][y]) {
        solve(x + 1, y, maze, n, vis, path + 'D', ans);
    }

    // Left
    if (y - 1 >= 0 && maze[x][y - 1] == 1 && !vis[x][y - 1]) {
        solve(x, y - 1, maze, n, vis, path + 'L', ans);
    }

    // Right
    if (y + 1 < n && maze[x][y + 1] == 1 && !vis[x][y + 1]) {
        solve(x, y + 1, maze, n, vis, path + 'R', ans);
    }

    // Up
    if (x - 1 >= 0 && maze[x - 1][y] == 1 && !vis[x - 1][y]) {
        solve(x - 1, y, maze, n, vis, path + 'U', ans);
    }

    // Backtrack
    vis[x][y] = 0;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        cout << -1;
        return 0;
    }

    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<string> ans;

    solve(0, 0, maze, n, vis, "", ans);

    if (ans.empty()) {
        cout << -1;
    } else {
        for (string path : ans) {
            cout << path << endl;
        }
    }

    return 0;
}