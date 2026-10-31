class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int LIMIT = 4000;

        vector<vector<bool>> dp(n+1, vector<bool>(LIMIT, false));

        // Base case
        dp[0][0] = true;

        for(int i = 0; i < n; i++) {
            for(int sum = 0; sum < LIMIT; sum++) {

                if(dp[i][sum]) {

                    // Not take
                    dp[i+1][sum] = true;

                    // Take
                    if(sum < nums[i] && sum + nums[i] < LIMIT) {
                        dp[i+1][sum + nums[i]] = true;
                    }
                }
            }
        }

        int ans = 0;

        for(int sum = 0; sum < LIMIT; sum++) {
            if(dp[n][sum]) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna