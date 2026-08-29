class Solution {
public:
int helper(int sr,int sc,int er,int ec,vector<vector<int>> &dp){
        if(sr>er || sc>ec){
            return 0;
        }
        if(dp[sr][sc] == -1) return 0;
        if(sr==er && sc == ec){
            return 1;
        } 
        if(dp[sr][sc] != -2) return dp[sr][sc];
        return dp[sr][sc] = helper(sr+1,sc,er,ec,dp) + helper(sr,sc+1,er,ec,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long int>>dp(m,vector<long long int>(n,0));
        
        // for(int i= 0 ; i<m ; i++){
        //     for(int j = 0 ; j<n ; j++){
        //         if(obstacleGrid[i][j] == 1){
        //             dp[i][j] = -1;
        //         } 
        //     }
        // }
        // return helper(0,0,m-1,n-1,dp);
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        dp[m-1][n-1] = 1;
        for(int i = m-2 ; i>=0 ; i--){
            if(obstacleGrid[i][n-1] == 1) dp[i][n-1] = 0;
            else dp[i][n-1] = dp[i+1][n-1];
        }
        for(int i = n-2 ; i>=0 ; i--){
            if(obstacleGrid[m-1][i] == 1) dp[m-1][i] = 0;
            else dp[m-1][i] = dp[m-1][i+1];
        }

        for(int i = m-2  ; i>=0 ; i--){
            for(int j = n-2 ; j>=0  ;j--){
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }

        return dp[0][0];


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna