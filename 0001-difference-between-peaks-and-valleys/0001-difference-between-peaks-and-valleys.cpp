class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        for(int i = 1 ; i< n-1 ; i++){
            if(nums[i]>nums[i-1] && nums[i] > nums[i+1]){
                high+=nums[i];
            }
            if(nums[i]<nums[i-1] && nums[i] < nums[i+1]){
                low+=nums[i];
            }
        }
        return high-low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna