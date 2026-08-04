class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>q;
        int maxi = 0;

        for(int i = 0 ; i<k ; i++){
            while(!q.empty() && nums[q.back()] <nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for(int i = k ; i<n ; i++){

            while(!q.empty() && q.front()<=i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()] <nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna