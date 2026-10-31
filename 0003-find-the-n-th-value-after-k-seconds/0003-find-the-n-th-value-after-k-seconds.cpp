class Solution {
public:
    const int MOD = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<int> prefix(n,1);
        
        for(int i = 0 ; i< k ; i++){
            for(int j = 1 ; j< n ; j++){
                prefix[j] = (prefix[j] + prefix[j-1])%MOD; 
            }
        }
        
        return prefix[n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna