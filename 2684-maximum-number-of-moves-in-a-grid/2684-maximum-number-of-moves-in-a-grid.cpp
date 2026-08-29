class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Last column
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = 0;
        }

        // Move from right to left
        for (int j = m - 2; j >= 0; j--) {

            for (int i = 0; i < n; i++) {

                int right = -1e8;
                int left = -1e8;
                int down = -1e8;

                // (i-1, j+1)
                if (i - 1 >= 0 &&
                    grid[i - 1][j + 1] > grid[i][j]) {

                    left = 1 + dp[i - 1][j + 1];
                }

                // (i, j+1)
                if (grid[i][j + 1] > grid[i][j]) {

                    right = 1 + dp[i][j + 1];
                }

                // (i+1, j+1)
                if (i + 1 < n &&
                    grid[i + 1][j + 1] > grid[i][j]) {

                    down = 1 + dp[i + 1][j + 1];
                }

                dp[i][j] = max({0, left, right, down});
            }
        }

        int ans = 0;

        // Can start from ANY row in column 0
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][0]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna