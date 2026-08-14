class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> dp;

        sort(nums.begin(),nums.end());
        int maxi = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            int curr = nums[i];

            dp[curr+1] = dp[curr] + 1;
            dp[curr] = dp[curr-1] + 1;
            
            maxi = max({dp[curr+1],dp[curr],maxi});
        }

        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna