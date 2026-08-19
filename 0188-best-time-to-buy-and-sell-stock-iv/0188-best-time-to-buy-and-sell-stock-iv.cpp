int dp[1005][105][2];
class Solution {
public:
    
    int f(vector<int>&profit ,int  i , int k , bool on){
        if(i==profit.size()){
            return 0;
        }
        if(dp[i][k][on]!= -1) return dp[i][k][on];
        int result = INT_MIN;
        if(on == true){
            result = max(result,f(profit,i+1,k-1,false) + profit[i]);
        }
        else if(on == false && k>0){
             result = max(result,f(profit,i+1,k,true) - profit[i]);
        }
        result = max(result,f(profit,i+1,k,on));

        return dp[i][k][on] = result;
     }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return f(prices,0,k,false);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna