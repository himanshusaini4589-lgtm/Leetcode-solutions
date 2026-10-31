class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(4000, 0));

        // Base case:
        // dp[n][currsum] = 0 (already initialized)

        for(int i = n-1; i >= 0; i--) {
            for(int currsum = 3999; currsum >= 0; currsum--) {

                int ntake = dp[i+1][currsum];

                int take = INT_MIN;

                if(currsum < nums[i] && currsum + nums[i] < 4000) {
                    take = nums[i] + dp[i+1][currsum + nums[i]];
                }

                dp[i][currsum] = max(ntake, take);
            }
        }

        return dp[0][0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna