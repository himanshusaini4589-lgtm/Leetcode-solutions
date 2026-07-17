class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> freq;
        freq[0] = -1;
        
        long long sum = 0;
        for (int i = 0 ; i<n ; i++) {
            sum += nums[i];
            int rem = sum%k;
            if (freq.count(rem)) {
                if(i-freq[rem] >= 2) return true;
            }
            else freq[rem] = i;
        }
        
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna