class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 1;

        for (int l = 0; l < n; l++) {
            int sum = 0;
            int rem = nums[l] % k;

            for (int r = l; r < n; r++) {
                if (nums[r] % k != rem) {
                    break;
                }

                sum += nums[r];

                int len = r - l + 1;

                if ((sum - nums[l]) % k == 0) {
                    maxi = max(maxi, len);
                }
            }
            if(maxi >= (n-l)) break;
        }

        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna