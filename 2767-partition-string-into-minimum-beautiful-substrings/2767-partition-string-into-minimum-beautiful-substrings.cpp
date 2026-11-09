class Solution {
public:
    bool check (string s){
        if(s.size() == 0) return false;
        if(s[0] == '0') return false;

        int t = 0;
        for(int i = s.length()-1 ; i>=0 ; i--){
            if(s[i]=='1'){
                t += 1<<(s.length()-i-1);
            }
        }
        if(t == 0) return false;

        while(t>1){
            if(t%5!=0){
                return false;
            }
            t/=5;
        }

        return true;
    }

    vector<int> dp;
    int f(int ind,string &s){
        if(ind==s.length()){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int ans = INT_MAX-1;
        
        for(int i = ind ; i<s.length() ; i++){
            if(check(s.substr(ind,i-ind+1))){
                ans = min(ans,1 + f(i+1,s));
            }
        }
        return dp[ind] = ans;
    }
    int minimumBeautifulSubstrings(string s) {
        
        int n = s.length();
        dp.resize(n+1,-1);
        int ans = f(0,s);
        if(ans == INT_MAX-1) return -1;
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna