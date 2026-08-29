class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(vector<vector<int>>& grid, int m, int n) {
        if (m < 0 || n < 0) return LLONG_MAX;
        if (m == 0 && n == 0) return grid[0][0];

        if (dp[m][n] != -1) return dp[m][n];

        long long ans = grid[m][n] +
            min(solve(grid, m-1, n), solve(grid, m, n-1));

        return dp[m][n] = ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<long long>(n, -1));

        return solve(grid, m-1, n-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna