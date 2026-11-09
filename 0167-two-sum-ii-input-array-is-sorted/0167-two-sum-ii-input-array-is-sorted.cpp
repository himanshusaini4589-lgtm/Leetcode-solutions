class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        // since array is sorted;
        while(i<j){
            int ans = nums[i] + nums[j];
            if( ans == target) return{i+1,j+1};
            if(ans < target){
                i++;
            }
            else{
                j--;
            }
        }
        return {-1,-1};

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna