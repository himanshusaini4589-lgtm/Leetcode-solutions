class Solution {
public:
    int n, m;
    vector<int> dr = {1, 1, -1, -1};
    vector<int> dc = {1, -1, -1, 1};

    int dp[500][500][4][2];

    int f(vector<vector<int>>& grid, int r, int c, int dir, int turned) {
        if (dp[r][c][dir][turned] != -1)
            return dp[r][c][dir][turned];

        int ans = 1;

        int nr = r + dr[dir];
        int nc = c + dc[dir];

        int expected = (grid[r][c] == 1) ? 2 : 2 - grid[r][c];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            grid[nr][nc] == expected) {
            ans = max(ans, 1 + f(grid, nr, nc, dir, turned));
        }

        if (!turned) {
            int ndir = (dir + 1) % 4;

            nr = r + dr[ndir];
            nc = c + dc[ndir];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == expected) {
                ans = max(ans, 1 + f(grid, nr, nc, ndir, 1));
            }
        }

        return dp[r][c][dir][turned] = ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        ans = max(ans, f(grid, i, j, dir, 0));
                    }
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna