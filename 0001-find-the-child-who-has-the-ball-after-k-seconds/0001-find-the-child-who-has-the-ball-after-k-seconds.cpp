class Solution {
public:
    int numberOfChild(int n, int k) {
        int final = k%(n-1);
        int div = k/(n-1);
        vector<int> v;
        for(int i = 0; i<n ; i++){
            v.push_back(i);
        }
        if(div%2 == 0){
            return v[final];
        } 
        return v[n-final-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna