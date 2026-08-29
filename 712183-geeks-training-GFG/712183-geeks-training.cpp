class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(3, 0));

        // Day 0
        dp[0][0] = mat[0][0];
        dp[0][1] = mat[0][1];
        dp[0][2] = mat[0][2];

        for (int i = 1; i < n; i++) {

            // Choose activity 0 today
            dp[i][0] = mat[i][0] + max(dp[i-1][1], dp[i-1][2]);

            // Choose activity 1 today
            dp[i][1] = mat[i][1] + max(dp[i-1][0], dp[i-1][2]);

            // Choose activity 2 today
            dp[i][2] = mat[i][2] + max(dp[i-1][0], dp[i-1][1]);
        }

        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna