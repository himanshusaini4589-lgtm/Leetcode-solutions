class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        int ans = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                // Bottom-right corner
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int future = INT_MIN;

                // Move down
                if (i + 1 < n) {
                    future = max(future, dp[i + 1][j]);
                }

                // Move right
                if (j + 1 < m) {
                    future = max(future, dp[i][j + 1]);
                }

                // Best score if we start from (i,j)
                ans = max(ans, future - grid[i][j]);

                // Maximum value reachable including current cell
                dp[i][j] = max(grid[i][j], future);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna