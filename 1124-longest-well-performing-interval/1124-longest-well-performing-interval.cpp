class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        for (int i = 0; i < n; i++) {
            if (hours[i] > 8)
                hours[i] = 1;
            else
                hours[i] = -1;
        }

        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += hours[i];

            if (sum > 0) {
                ans = i + 1;
            } else {
                if (mp.count(sum - 1))
                    ans = max(ans, i - mp[sum - 1]);
            }

            // Store first occurrence only
            if (!mp.count(sum))
                mp[sum] = i;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna