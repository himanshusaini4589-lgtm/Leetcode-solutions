class Solution {
public:

    int dp[5001][3];

    int f(vector<int>& price, int ind, int state) {

        if (ind >= price.size())
            return 0;

        if (dp[ind][state] != -1)
            return dp[ind][state];

        int profit = 0;

        if (state == 0) {
            // Can buy
            profit = max(
                -price[ind]  + f(price, ind + 1, 1),
                f(price, ind + 1, 0)
            );
        }

        else if (state == 1) {
            // Holding stock
            profit = max(
                price[ind] + f(price, ind + 1, 2),
                f(price, ind + 1, 1)
            );
        }

        else {
            // Cooldown
            profit = f(price, ind + 1, 0);
        }

        return dp[ind][state] = profit;
    }

    int maxProfit(vector<int>& price) {

        memset(dp, -1, sizeof(dp));

        return f(price, 0, 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna