class Solution {
public:


    int almostPalindromic(string s) {

        int n = s.size();
        int ans = 0;
        
        //appling bottom up dp 

        vector<vector<bool> >pal(n,vector<bool>(n,false));
        vector<vector<bool> >dp(n,vector<bool>(n,false));
        for(int i = 0 ; i< n; i++){
            pal[i][i] = true;
            dp[i][i] = true;
        }

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = i+1 ; j<n ; j++){
                if(s[i]==s[j]){
                    if (j - i == 1) pal[i][j] = true;
                    else{
                        pal[i][j] = pal[i+1][j-1];
                    }
                }
            }
        }

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = i+1 ; j<n ; j++){

                if(s[i]==s[j]){
                    if (j - i == 1) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }
                else{
                    bool dleft = pal[i][j-1];
                    bool dright = pal[i+1][j];
                    dp[i][j] = dleft || dright ;
                }
                if(dp[i][j]) ans = max(ans,j-i+1);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna