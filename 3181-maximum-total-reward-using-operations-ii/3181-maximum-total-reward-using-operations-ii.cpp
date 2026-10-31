class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bitset<100001>dp,mask,pref;
        int maskid = 0;
        dp[0] = 1;
        for(auto ele : nums){
            while(maskid < ele) mask[maskid++] = 1;

            pref = dp&mask;
            dp |= pref<<ele;
        }
        int res = 1e5;
        while(!dp[res]) res--;
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna