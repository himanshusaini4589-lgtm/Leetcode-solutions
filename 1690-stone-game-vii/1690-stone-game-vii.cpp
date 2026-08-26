class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pref;

    int rangeSum(int l, int r){
        return pref[r + 1] - pref[l];
    }

    int f(int i, int j){
        if(i == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int removeLeft =
            rangeSum(i + 1, j) - f(i + 1, j);
        int removeRight =
            rangeSum(i, j - 1) - f(i, j - 1);
        return dp[i][j] =
            max(removeLeft, removeRight);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        pref.resize(n + 1, 0);
        for(int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + stones[i];
        dp.assign(n, vector<int>(n, -1));
        return f(0, n - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna