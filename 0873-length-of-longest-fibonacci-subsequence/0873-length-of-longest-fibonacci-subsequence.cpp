class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));

        int ans = 0;

        for (int j = 0; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                int need = arr[k] - arr[j];

                if (mp.count(need)) {

                    int i = mp[need];

                    if (i < j) {
                        dp[j][k] = dp[i][j] + 1;
                    }
                }

                ans = max(ans, dp[j][k]);
            }
        }

        return ans >= 3 ? ans : 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna