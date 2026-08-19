class Solution {
public:
    int dp[50005][3];
    int f(vector<int>& price , int ind ,int buy ,int fee ){

        if(ind>=price.size()){
            return 0;
        } 
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = 0 ;
        if(buy){
            profit +=  max(-fee - price[ind]+f(price,ind+1,!buy,fee),f(price,ind+1,buy,fee));
        }
        else{
            profit += max(price[ind]+f(price,ind+1,!buy,fee),f(price,ind+1,buy,fee));
        }
        return dp[ind][buy] =  profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return f(prices,0,1,fee);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna