class Solution {
public:

    bool pali(string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int f(string &s, int i, vector<int> &dp) {

        if (i >= s.length()) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        int mini = INT_MAX;

        for (int k = i; k < s.length(); k++) {

            if (pali(s, i, k)) {
                mini = min(mini, 1 + f(s, k + 1, dp));
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {

        int n = s.length();

        vector<int> dp(n, -1);

        return f(s, 0, dp) - 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna