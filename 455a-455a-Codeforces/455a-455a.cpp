#include <bits/stdc++.h>#include<vector>#include<unordered_map>using namespace std; const int MOD = 1000000007; int main() {    int n;    cin >> n;    vector<int>v;    int maxi = INT_MIN;    vector<long long> a(100005,0);    for(int i = 0 ; i<n ; i++){        int q;        cin>>q;        v.push_back(q);        a[q]++;        maxi = max(maxi,q);    }     vector<long long>dp(100005,0);    dp[0] = 0;    dp[1] = a[1];    for(int i = 2 ; i<=100000 ; i++){        dp[i] = max(dp[i-1],dp[i-2] + a[i]*i);    }    cout<<dp[maxi]<<endl;} 

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna