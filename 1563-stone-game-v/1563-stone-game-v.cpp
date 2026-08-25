class Solution {
public:
    int dp[501][501];
    int f(vector<int>& nums, int start, int end, vector<int>& prefix) {
        if (start >= end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans = 0;
        for (int k = start; k < end; k++) {

            int leftSum = prefix[k + 1] - prefix[start];
            int rightSum = prefix[end + 1] - prefix[k + 1];

            if (leftSum < rightSum) {
                ans = max(ans,
                    leftSum + f(nums, start, k, prefix)
                );
            }
            else if (rightSum < leftSum) {
                ans = max(ans,
                    rightSum + f(nums, k + 1, end, prefix)
                );
            }
            else {
                ans = max(ans,
                    leftSum + max(
                        f(nums, start, k, prefix),
                        f(nums, k + 1, end, prefix)
                    )
                );
            }
        }

        return dp[start][end] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp,-1,sizeof(dp));
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return f(stoneValue, 0, n - 1, prefix);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna