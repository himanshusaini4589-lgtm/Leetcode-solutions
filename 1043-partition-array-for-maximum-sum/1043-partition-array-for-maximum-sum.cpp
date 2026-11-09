class Solution {
public:

    vector<int> dp;
    int f(int ind,vector<int> &arr,int k){
        if(ind>=arr.size()) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int ans = INT_MIN;
        int len_max = arr[ind];
        for(int i = ind ; i<ind+k && i<arr.size() ; i++){
            len_max = max(len_max,arr[i]);
            int curr_len = i-ind+1;
            int sum = len_max*curr_len + f(i+1,arr,k);
            ans = max(ans,sum);
        }

        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.resize(n+1,-1);
        return f(0,arr,k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna