class Solution {
public:
    int helper(int sr,int sc,int er,int ec,vector<vector<int>> &dp){
        if(sr==er && sc == ec){
            return 1;
        }
        if(sr>er || sc>ec){
            return 0;
        }
        if(dp[sr][sc] != -1) return dp[sr][sc];

        return dp[sr][sc] = helper(sr+1,sc,er,ec,dp) + helper(sr,sc+1,er,ec,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        //return helper(0,0,m-1,n-1,dp); 

        dp[m-1][n-1] = 0;
        for(int i = 0 ; i<m ; i++){
            dp[i][0] = 1;
        }
        for(int i = 0 ; i<n ; i++){
            dp[0][i] = 1;
        }
        for(int i = 1 ; i<m ; i++){
            for(int j = 1 ; j<n ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        } 
        return dp[m-1][n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna