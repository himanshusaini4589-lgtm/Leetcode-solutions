class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int v : nums) freq[v]++;

        map<int,int> mp;
        sort(nums.begin(),nums.end());
        for (int v : nums) {
            mp[v-k]++;

            mp[v+k+1]--;
            mp[v]+=0;
        }
        int cumsum = 0;
        int ans = INT_MIN;
        for(auto it = mp.begin() ; it!=mp.end() ; it++){
            it->second += cumsum;

            int target = it->first;
            int fr = freq[target];

            int required = it->second - fr;
            
            ans = max(ans, fr + min(numOperations,required));
            cumsum = it->second;
        }

        return ans;


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna