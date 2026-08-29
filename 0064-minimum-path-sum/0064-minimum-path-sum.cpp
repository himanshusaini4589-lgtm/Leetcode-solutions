class Solution {
public:
    vector<vector<long long>> dp;

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<long long>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1 ; i< n ; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1 ; i< m ; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i = 1 ; i< m ; i++ ){
            for(int j = 1 ; j<n ; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna