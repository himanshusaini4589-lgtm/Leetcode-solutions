#include<iostream>#include<vector>#include<algorithm>using namespace std;int main(){    int t;    cin>>t;    while(t--){      int n ;      cin>>n;      vector<int> v(n);      for(int i = 0 ; i<n ; i++){        cin>>v[i];      }      vector<long long>dp(n+1,0);      dp[n-1] = 1;       for(int i = n-2 ; i>=0 ; i--){         long long h = LONG_MAX;        if(i+v[i]<n){            h = dp[i+v[i]+1];        }        dp[i] = min(1 + dp[i+1],h);      }      cout<<dp[0]<<endl;    }}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna