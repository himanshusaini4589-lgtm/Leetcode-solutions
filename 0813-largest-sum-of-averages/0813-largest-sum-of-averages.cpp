class Solution {
public:

    double f(int i, int k, vector<int>& nums,
             vector<int>& prefix,
             vector<vector<double>>& dp) {

        int n = nums.size();

        // One group left
        if (k == 1) {
            return (double)(prefix[n] - prefix[i]) / (n - i);
        }

        if (dp[i][k] != -1)
            return dp[i][k];

        double ans = 0;

        int sum = 0;

        // Current group: [i ... j]
        for (int j = i; j <= n - k; j++) {

            sum += nums[j];

            double avg = (double)sum / (j - i + 1);

            double remaining = f(
                j + 1,
                k - 1,
                nums,
                prefix,
                dp
            );

            ans = max(ans, avg + remaining);
        }

        return dp[i][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<vector<double>> dp(
            n,
            vector<double>(k + 1, -1)
        );

        return f(0, k, nums, prefix, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna