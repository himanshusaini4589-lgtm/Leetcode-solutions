class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        int ans = 0 ;
        unordered_map<int,int>mp;
        for(int i = 0 ; i<n ; i++){
            mp[text[i]]++;
        }
        for(int i = 'a' ; i<='z' ; i++){
            int l = 0 ;
            int lmax = 0;
            int cnt = 0;
            for(int r = 0 ; r<n ; r++){
                if(text[r]==i) cnt++;
                while(r-l+1>cnt+1){
                    if(text[l]==i) cnt--;
                    l++;
                }

                lmax = min(r-l+1,mp[i]);
                ans = max(lmax,ans);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna