class Solution {
public:
    static const int MOD = 1000000007;

    int checkRecord(int n) {

        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(3, vector<long long>(2, 0))
        );

        // Empty string
        dp[0][0][0] = 1;

        for (int len = 0; len < n; len++) {

            for (int L = 0; L < 3; L++) {
                for (int A = 0; A < 2; A++) {

                    long long cur = dp[len][L][A];

                    if (cur == 0)
                        continue;
                        
                    // Add P
                    dp[len + 1][0][A] =
                        (dp[len + 1][0][A] + cur) % MOD;

                    // Add L
                    if (L < 2) {
                        dp[len + 1][L + 1][A] =
                            (dp[len + 1][L + 1][A] + cur) % MOD;
                    }

                    // Add A
                    if (A < 1) {
                        dp[len + 1][0][A + 1] =
                            (dp[len + 1][0][A + 1] + cur) % MOD;
                    }
                }
            }
        }

        long long ans = 0;

        for (int L = 0; L < 3; L++) {
            for (int A = 0; A < 2; A++) {
                ans = (ans + dp[n][L][A]) % MOD;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna