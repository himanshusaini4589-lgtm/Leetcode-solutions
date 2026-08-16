class Solution {
public:
    vector<long long> dp;

    long long solve(int target, vector<int>& nums) {
        if (target == 0) return 1;
        if (target < 0) return 0;

        if (dp[target] != -1) return dp[target];

        long long ways = 0;

        for (int num : nums) {
            ways += solve(target - num, nums);
        }

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return solve(target, nums);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna