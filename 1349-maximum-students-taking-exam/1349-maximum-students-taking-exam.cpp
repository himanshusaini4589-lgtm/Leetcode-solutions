class Solution {
public:
    int n,m;
    bool valid(int mask ,int row,vector<vector<char>>& seats){
        if(mask & (mask<<1)) return false;

        for(int j = 0 ; j<m; j++){
            if(seats[row][j]=='#' && mask&(1<<j)){
                return false;
            }
        }
        return true;
    }
    bool possible(int mask,int prev){
        if(mask&(prev<<1)) return false;
        if(mask&(prev>>1)) return false;
        return true;
    }

    vector<vector<int> > dp;
    int f(int i,int prev,vector<vector<char>>& seats){
        if(i>=n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans = 0;
        for(int mask = 0 ; mask<(1<<m) ; mask++){
            if(!valid(mask,i,seats)) continue;
            if(!possible(mask,prev)) continue;

            int cnt = __builtin_popcount(mask);
            ans = max(ans,cnt + f(i+1,mask,seats));
        }
        return dp[i][prev] = ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        n = seats.size();
        m = seats[0].size();
        dp.resize(n+1,vector<int>(1<<m,-1));
        int ans = f(0,0,seats);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna