class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int l = 0;
        int n = s.length();

        for(int r = 0; r<n ;r++){
            if(r>1 && s[r]=='c' && s[r-1] == 'b' && s[r-2] == 'a'){
                l = r-1;
            }
            ans += (r-l+1);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna