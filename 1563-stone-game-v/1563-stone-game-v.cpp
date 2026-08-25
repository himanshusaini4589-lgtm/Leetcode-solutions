class Solution {
public:
    int dp[501][501];
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp,0,sizeof(dp));
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        for(int start = n-1 ; start>=0 ; start--){
            for(int end = 0 ; end<n ; end++){
                if(start>=end){
                    dp[start][end] = 0;
                    continue;
                } 
                int ans = 0;

                for (int k = start; k < end; k++) {

                    int leftSum = prefix[k + 1] - prefix[start];
                    int rightSum = prefix[end + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {
                        ans = max(ans,
                            leftSum + dp[start][k]
                        );
                    }
                    else if (rightSum < leftSum) {
                        ans = max(ans,
                            rightSum + dp[k+1][end]
                        );
                    }
                    else {
                        ans = max(ans,
                            leftSum + max(
                                dp[start][k],
                                dp[k+1][end]
                            )
                        );
                    }
                }
                dp[start][end] = ans;
            }
        }
        return dp[0][n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna