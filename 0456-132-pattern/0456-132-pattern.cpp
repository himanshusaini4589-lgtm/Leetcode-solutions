class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int third = INT_MIN;

        for(int i = n-1; i >= 0; i--) {
            if(nums[i] < third)
                return true;

            while(!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna