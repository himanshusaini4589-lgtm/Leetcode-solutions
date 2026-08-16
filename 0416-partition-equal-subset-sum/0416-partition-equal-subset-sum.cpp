class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool> > dp(n,vector<bool>(target+1,false));

        for(int i = 0 ; i<n ; i++) dp[i][0] = true;
        for(int i = 0 ; i<=target ; i++) if(nums[0]==i) dp[0][i] = true;
        for(int i = 1 ; i<n ; i++){
            for(int j = 1 ; j<=target ; j++){
                dp[i][j] = dp[i-1][j] || (j-nums[i] >=0 ? dp[i-1][j-nums[i]] : false );
            }
        }
        return dp[n-1][target];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna