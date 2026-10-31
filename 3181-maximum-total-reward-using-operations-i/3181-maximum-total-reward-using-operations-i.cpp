class Solution {
public:
    int n;
    //int ans = INT_MIN;
    
    int f(vector<int> &nums,int i,int currsum,vector<vector<int> > &mpp){
        if(i>=n){
            //ans = max(ans,currsum);
            return 0;
        } 
        if(mpp[i][currsum]!= -1) return mpp[i][currsum];
        int ntake = f(nums,i+1,currsum,mpp);
        int take = INT_MIN;
        if(currsum < nums[i]){
            take = nums[i] + f(nums,i+1,currsum+nums[i],mpp);
        }
        return mpp[i][currsum] = max(ntake,take);
    }
    
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        vector<vector<int> >  mpp(n+1,vector<int>(4000,-1));
        int ans = f(nums,0,0,mpp);
        return ans;


        // vector<int>dp(n,0);
        // for(int i = 0 ; i< n ; i++){
        //     int sum = 0;
        //     for(int j = 0 ; j<i ; j++){
        //         dp[i] = nums[i];
        //         if(sum<nums[i]){
        //             if(dp[i] < dp[j] + nums[i]){
        //                 dp[i] = dp[i] + dp[j];
        //                 sum += nums[i];
        //             }
        //         }
                
        //     }
        // }
        // return dp[n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna