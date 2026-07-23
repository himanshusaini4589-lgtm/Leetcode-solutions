class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return ((start[0] + start[1]) % 2) ==
               ((target[0] + target[1]) % 2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna