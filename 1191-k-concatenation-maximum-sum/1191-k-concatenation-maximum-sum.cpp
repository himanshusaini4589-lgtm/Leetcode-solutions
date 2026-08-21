#define ll long long
class Solution {
public:
    static const int MOD = 1000000007;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();

        ll sum = 0;
        ll maxsum = 0;
        
        int totalsum = 0;
        for(auto ele : arr){
            totalsum+= ele;
        }

        int times = min(k,2);

        for(int i = 0 ; i<times ; i++){
            for(int j = 0 ; j<n ; j++){
                if(sum>=0){
                    sum= (sum + arr[j]);
                }
                else{
                    sum = arr[j];
                }
                maxsum = max(maxsum,sum);
            }
        }

        if(k>2 && totalsum>0){
            maxsum = (maxsum + (ll)(k-2)*totalsum);
        }
        return maxsum%MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna