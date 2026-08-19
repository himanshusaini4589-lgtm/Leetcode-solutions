#define mod 1000000007
#define ll long long int 
class Solution {
public:
    vector<vector<ll> > dp;
    ll sum(int k, int n , int target ){
        if(target==0 && n==0) return 1;
        if(n==0 ) return 0;
        
        if(dp[n][target]!=-1) return dp[n][target];
        ll count = 0 ;
        for(int i = 1 ; i<= k ; i++){
            if(target - i< 0) break;
            count += sum(k,n-1,target-i)%mod;
        }
        return dp[n][target] = count%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(35 , vector<ll>(1005,-1));
        return sum(k,n,target);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna