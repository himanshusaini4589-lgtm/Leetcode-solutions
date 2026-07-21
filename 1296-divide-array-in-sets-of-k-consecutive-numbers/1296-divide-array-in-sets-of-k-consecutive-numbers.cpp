class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto el : nums){
            mp[el]++;
        }
        sort(nums.begin(),nums.end());
        for(auto ele : nums){
            if(mp[ele]==0) continue;
            for(int i = 0 ; i<k ; i++){
                if(mp[ele+i]==0) return false;
                mp[ele+i]--;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna