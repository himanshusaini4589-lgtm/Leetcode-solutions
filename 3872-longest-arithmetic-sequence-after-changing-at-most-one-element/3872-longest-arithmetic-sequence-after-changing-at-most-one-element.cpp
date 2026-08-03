class Solution {
    // Returns the longest arithmetic sequence, based on a slinding window
    int getLongestArithmetic(vector<int>& nums) {
        int max_len = 2, diff = nums[1] - nums[0], n = nums.size();
        for (int l = 0, r = 2; r < n; r++) {
            int cur_diff = nums[r] - nums[r - 1];
            if (cur_diff == diff) {
                max_len = max(max_len, r - l + 1);
                continue;
            }
                
            // Change at most one element by scanning forward with tmp_r
            int pre_r = r - 1, tmp_r = r;
            int cur = nums[r - 1] + diff;
            while (tmp_r + 1 < n && nums[tmp_r + 1] - cur == diff) {
                cur = nums[tmp_r + 1];
                tmp_r++;
            }

            max_len = max(max_len, tmp_r - l + 1);
            diff = cur_diff;
            l = pre_r;
        }

        return max_len;
    }
    
public:
    int longestArithmetic(vector<int>& nums) {
        int max_len = getLongestArithmetic(nums);
        reverse(nums.begin(), nums.end());
        return max(max_len, getLongestArithmetic(nums));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna