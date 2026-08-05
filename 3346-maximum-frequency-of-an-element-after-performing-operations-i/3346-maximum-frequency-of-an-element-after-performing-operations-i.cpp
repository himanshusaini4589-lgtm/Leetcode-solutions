class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int v : nums) freq[v]++;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // Candidate targets: every point where s(x) or cnt[x] can change
        vector<int> candidates;
        candidates.reserve(3 * n);
        for (int v : nums) {
            candidates.push_back(v - k);
            candidates.push_back(v);
            candidates.push_back(v + k + 1);
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        int lo = 0, hi = 0, ans = 0;
        for (int x : candidates) {
            // Window [x-k, x+k] translates monotonically as x increases
            while (hi < n && sortedNums[hi] <= x + k) hi++;
            while (lo < n && sortedNums[lo] < x - k) lo++;

            int s = hi - lo;                       // total reachable count
            int same = freq.count(x) ? freq[x] : 0; // free matches at x
            ans = max(ans, min(s, same + numOperations));
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna