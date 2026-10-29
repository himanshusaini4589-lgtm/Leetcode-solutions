class Solution {
public:


    int f(vector<int>&nums,int k){
        int n = nums.size();
        int l = 0 ; 

        int cnt = 0;
        unordered_map<int,int>mpp;
        for(int r = 0 ; r<n ; r++){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                if(mpp.find(nums[l])!=mpp.end()){
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                }
                l++;
            }
            cnt +=(r-l+1);
        }

        return cnt;
    }



    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna