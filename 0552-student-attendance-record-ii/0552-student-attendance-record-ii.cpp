class Solution {
public:
    static const int MOD = 1000000007;

    int checkRecord(int n) {

        // dp[L][A]
        // L = consecutive L's at the end
        // A = number of A's used

        long long dp[3][2] = {};

        // Empty string
        dp[0][0] = 1;

        for (int len = 0; len < n; len++) {

            long long ndp[3][2] = {};

            for (int L = 0; L < 3; L++) {
                for (int A = 0; A < 2; A++) {

                    long long cur = dp[L][A];

                    // Add P
                    ndp[0][A] =
                        (ndp[0][A] + cur) % MOD;

                    // Add L
                    if (L < 2) {
                        ndp[L + 1][A] =
                            (ndp[L + 1][A] + cur) % MOD;
                    }

                    // Add A
                    if (A < 1) {
                        ndp[0][A + 1] =
                            (ndp[0][A + 1] + cur) % MOD;
                    }
                }
            }

            // Move to next length
            memcpy(dp, ndp, sizeof(dp));
        }

        // Every state after n characters is valid
        long long ans = 0;

        for (int L = 0; L < 3; L++) {
            for (int A = 0; A < 2; A++) {
                ans = (ans + dp[L][A]) % MOD;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna