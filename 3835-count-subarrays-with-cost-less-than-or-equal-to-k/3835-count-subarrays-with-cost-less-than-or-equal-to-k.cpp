class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        deque<int>maxi;
        deque<int>mini;
        int left = 0;
        long long ans = 0;

        for(int right = 0 ; right<n ; right++){
            while(maxi.size() && nums[maxi.back()] <= nums[right]){
                maxi.pop_back();
            }
            while(mini.size() && nums[mini.back()] >= nums[right]){
                mini.pop_back();
            }
            maxi.push_back(right);
            mini.push_back(right);

            while(left<=right && (long long)(nums[maxi.front()] - nums[mini.front()])*(right-left +1) > k){
                if(maxi.front() == left) maxi.pop_front();
                if(mini.front() == left) mini.pop_front();
                left++;
            }
            ans += (right-left+1);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna