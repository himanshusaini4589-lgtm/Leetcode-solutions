class Solution {
public:
    int n;
    vector<int> a;
    vector<array<array<long long, 2>, 2>> memo;   // memo[i][d][p]

    // best extra sum from index i onward
    // d = 1 -> deletion still available
    // p = parity of the next taken element (0 -> +, 1 -> -)
    long long f(int i, int d, int p) {
        if (i == n) return 0;
        if (memo[i][d][p] != -1) return memo[i][d][p];   // f is always >= 0, so -1 means "not computed"

        long long best = 0;                               // stop here
        long long v = p ? -a[i] : a[i];
        best = max(best, v + f(i + 1, d, p ^ 1));         // take a[i]
        if (d) best = max(best, f(i + 1, 0, p));          // delete a[i], parity unchanged

        return memo[i][d][p] = best;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        a = nums;
        n = a.size();
        memo.assign(n, {{{-1, -1}, {-1, -1}}});

        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            // subarray starts at i with parity 0 (+), next element has parity 1 (-), deletion still available
            ans = max(ans, (long long)a[i] + f(i + 1, 1, 1));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna