class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();

        if ((n - 1) % (K - 1) != 0) return -1;

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int g = 1; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {

                int ans = 1e9;

                for (int mid = i; mid < j; mid += K - 1) {
                    ans = min(ans, dp[i][mid] + dp[mid + 1][j]);
                }

                dp[i][j] = ans;

                // Current interval can finally become one pile
                if (g % (K - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna