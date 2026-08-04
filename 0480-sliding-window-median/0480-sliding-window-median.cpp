class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> ans;

        for (int i = k; ; i++) {
            ans.push_back(k % 2 ? *mid : ((double)*mid + *prev(mid)) / 2.0);

            if (i == nums.size()) break;

            window.insert(nums[i]);
            if (nums[i] < *mid) mid--;

            if (nums[i - k] <= *mid) mid++;
            window.erase(window.find(nums[i - k]));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna