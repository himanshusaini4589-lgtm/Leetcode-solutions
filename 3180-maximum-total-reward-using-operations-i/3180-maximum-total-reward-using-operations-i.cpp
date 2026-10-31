class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        bitset<4001> dp,mask;
        dp[0] = 1;
        int maskid = 0;
        for(int x : nums) {
            while(maskid < x) mask[maskid++] = 1;
            dp |= (dp & mask) << x;
        }

        for(int i = 4000; i >= 0; i--) {
            if(dp[i]) return i;
        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna