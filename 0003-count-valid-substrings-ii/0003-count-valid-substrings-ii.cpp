class Solution {
public:
    
    long long countValidSubstrings(string s) {
        int n = s.length();
        vector<int> ind(n,-1);
        int l = 0;
        int b = -1;
        long long ans = 0;
        for(int i = 0 ; i< n; i++){
            if(s[i] == 'a') ind[i] = i;
            else if(i>0) ind[i] = ind[i-1];

            if(s[i] == 'b'){
                b = i;
            }
            if(s[i] == 'c'){
                if(b != -1){
                    l = ind[b] +1;
                }
            }
            ans += (i-l+1);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna