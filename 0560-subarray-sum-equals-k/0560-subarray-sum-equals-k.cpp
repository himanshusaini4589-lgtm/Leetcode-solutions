class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long,int>mp;
        long long sum = 0;
        int count = 0 ;
        mp[0] = 1;
        for(int i = 0 ; i<n ; i++){
            sum += nums[i];
            if(mp.find(sum-k)!=mp.end()){
                count += mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna