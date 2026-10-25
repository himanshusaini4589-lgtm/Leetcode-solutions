class Solution {
public:
    long long countMagicalPairs(string s) {
        // first of all we calculate pre
        //then suff
        // pre stores the last occurance of particular char
        //suff stores the latest occrurance of the particular char
        int n = s.length();
        vector<vector<int> > pre(n,vector<int>(26,-1));

        for(int i = 0 ; i<n ; i++){
            if(i>0){
                pre[i] = pre[i-1];
            }
            pre[i][s[i]-'a'] = i;
        }

        vector<vector<int> > suff(n,vector<int>(26,n));

        for(int i = n-1 ; i>=0 ; i--){
            if(i+1<n){
                suff[i] = suff[i+1];
            }
            suff[i][s[i]-'a'] = i;
        }

        long long ans = 0;
        for(int m = 1; m<n ; m++){
            int i = m-1;
            int j = m;
            vector<bool>p(26,false);
            vector<bool>sf(26,false);
            while(i>=0 && j<n){
                p[s[i] - 'a'] = true;
                sf[s[j] - 'a'] = true;
                

                int ii = -1;
                for(int t = 0 ; t<26 ; t++){
                    if(!p[t]){
                        ii = max(ii,pre[i][t]);
                    }
                }

                int jj = n;
                for(int t = 0 ; t<26 ; t++){
                    if(!sf[t]){
                        jj = min(jj,suff[j][t]);
                    }
                }

                ans += 1LL*(i-ii) * (jj-j);
                i=ii;
                j=jj;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna