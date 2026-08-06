class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for (int num : nums)
            total += num;

        int target = total - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return n;

        int left = 0;
        int sum = 0;
        int longest = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        return longest == -1 ? -1 : n - longest;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna