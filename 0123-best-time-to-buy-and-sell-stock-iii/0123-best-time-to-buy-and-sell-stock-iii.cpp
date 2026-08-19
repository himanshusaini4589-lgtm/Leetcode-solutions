
int dp[100005][10][2];
class Solution {
public:
    
    int f(vector<int>&profit ,int  i , int k , bool on){
        if(i==profit.size()){
            return 0;
        }
        if(dp[i][k][on]!= -1) return dp[i][k][on];
        int result = 0;

        if(on){
            result = max(result,f(profit,i+1,k,false)-profit[i]);
            result = max(result ,  f(profit,i+1,k,true));
        }

        else if(!on && k>0){
            result = max(result,f(profit,i+1,k-1,true) + profit[i]);
            result = max(result,f(profit,i+1,k,false));
        }

        return dp[i][k][on] = result;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[i][buy][cap]
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0))
        );

        // Build DP table backward
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    if (buy == 1) {
                        // Can buy
                        dp[i][buy][cap] = max(
                            -prices[i] + dp[i + 1][0][cap], // buy today
                            dp[i + 1][1][cap]               // skip
                        );
                    } else {
                        // Can sell
                        dp[i][buy][cap] = max(
                            prices[i] + dp[i + 1][1][cap - 1], // sell today
                            dp[i + 1][0][cap]                  // skip
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna