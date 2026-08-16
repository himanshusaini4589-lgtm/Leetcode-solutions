class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        vector<int>prev (n,0);
        for(int i = 0 ; i< n ; i++){
            prev[i] = triangle[n-1][i];
        }
        vector<int>curr = prev;
        for(int i = n-2 ; i>=0 ; i--){
            for(int j = 0 ; j<=i ; j++){
                curr[j] = triangle[i][j] + min(prev[j],prev[j+1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna