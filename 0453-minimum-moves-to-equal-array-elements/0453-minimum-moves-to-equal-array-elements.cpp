class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int mini= *min_element(nums.begin(),nums.end());
        int n = nums.size();

        return sum - mini*n;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna