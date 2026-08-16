#define MOD 1000000007
class Solution {
public:

    long long f(int node, int n,
                vector<vector<int>>& m,
                vector<vector<long long>>& dp) {

        if (n == 0)
            return 1;

        if (dp[node][n] != -1)
            return dp[node][n];

        long long ways = 0;

        for (int next : m[node]) {
            ways = (ways + f(next, n - 1, m, dp))%MOD;
        }

        return dp[node][n] = ways;
    }

    int knightDialer(int n) {

        vector<vector<int>> m(10);

        m[0] = {4, 6};
        m[1] = {6, 8};
        m[2] = {7, 9};
        m[3] = {4, 8};
        m[4] = {0, 3, 9};
        m[5] = {};
        m[6] = {0, 1, 7};
        m[7] = {2, 6};
        m[8] = {1, 3};
        m[9] = {2, 4};

        vector<vector<long long>> dp(
            10, vector<long long>(n, -1)
        );

        long long ans = 0;

        for (int i = 0; i <= 9; i++) {
            ans += f(i, n - 1, m, dp);
        }

        return ans % 1000000007;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna