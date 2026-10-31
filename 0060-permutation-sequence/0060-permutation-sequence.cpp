class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;

        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        int fact = 1;

        for(int i = 1; i < n; i++) {
            fact *= i;
        }

        k--;

        string s = "";

        while(nums.size()) {

            int index = k / fact;

            s += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            if(nums.size() == 0) break;

            k %= fact;

            fact /= nums.size();
        }

        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna