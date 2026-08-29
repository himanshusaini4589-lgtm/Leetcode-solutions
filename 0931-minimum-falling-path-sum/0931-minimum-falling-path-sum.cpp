class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0 ; i<n ; i++){
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for(int j = 0 ; j<n ; j++){
                int down = matrix[i][j] + dp[i-1][j];
                

                int left = INT_MAX;
                if (j > 0) left = matrix[i][j] + dp[i-1][j-1];

                int right = INT_MAX;
                if (j < n-1) right = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min({down, left, right});
            }
        }

        for(int i = 0 ; i<n ; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna