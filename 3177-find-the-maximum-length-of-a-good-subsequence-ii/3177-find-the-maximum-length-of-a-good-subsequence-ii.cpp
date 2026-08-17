class Solution {
public:

    int maximumLength(vector<int>& nums, int k) {

        unordered_map<int, vector<int>> dp;

        vector<int> maxDpFork(k + 1, 0);

        for (int x : nums) {
            if (!dp.count(x)) {
                dp[x] = vector<int>(k + 1, 0);
            }
            for (int remk = k; remk >= 0; remk--) {
                int same = dp[x][remk] + 1;
                int different = 1;

                if (remk > 0) {
                    different = maxDpFork[remk - 1] + 1;
                }

                dp[x][remk] = max(dp[x][remk],max(same, different));

                maxDpFork[remk] = max(maxDpFork[remk],dp[x][remk]);
            }
        }

        return maxDpFork[k];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna