class Solution {
public:
    int minMergedInteger(vector<int>& nums) {

        int n = nums.size();

        int mini = INT_MAX;

        for(int i = 0 ; i< n-1 ; i+=2){
            int first = nums[i];
            int second = nums[i+1];
            string t = to_string(first) + to_string(second);
            mini = min(mini,stoi(t));
        }

        return mini;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna