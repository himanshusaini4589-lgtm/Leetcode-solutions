class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);  // stores last index of each char
        int maxLen = 0, l = 0;
        int n = s.length();
        int r = 0;
        while(r<n){
            while(lastIndex[s[r]]>=l){
                l++;
            }
            lastIndex[s[r]] = r;
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna