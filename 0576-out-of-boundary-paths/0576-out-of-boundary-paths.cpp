#define MOD 1000000007
class Solution {
public:
    vector<int>dr = {-1,0,1,0};
    vector<int>dc = {0,1,0,-1};
    int dp[51][51][51];

    int f(int count,int maxMove ,int cr,int cc ,int r,int c){
        
        if (cr < 0 || cr >= r || cc < 0 || cc >= c)
            return 1;

        if(count==maxMove) return 0;
        if(dp[count][cr][cc]!= -1 ) return dp[count][cr][cc];
        int total = 0;

        for(int i = 0 ; i<4 ; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            total = (total+f(count+1,maxMove,nr,nc,r,c))%MOD;
        }

        return dp[count][cr][cc] =  total%MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int total = 0;
        memset(dp,-1,sizeof(dp));
        total = f(0,maxMove,startRow,startColumn,m,n);

        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna