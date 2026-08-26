class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;
    int K;

    int getSum(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }

    int f(int i, int j) {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int m = i; m < j; m += K - 1) {
            ans = min(ans,
                      f(i, m) + f(m + 1, j));
        }

        if ((j - i) % (K - 1) == 0) {
            ans += getSum(i, j);
        }

        return dp[i][j] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        K = k;
        int n = stones.size();

        if ((n - 1) % (K - 1) != 0)
            return -1;

        prefix.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        dp.assign(n, vector<int>(n, -1));

        return f(0, n - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna