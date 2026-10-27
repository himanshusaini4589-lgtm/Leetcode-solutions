class Solution {
public:
    vector<string> createGrid(int m, int n) {
        int count1 = 0;
        vector<string>ans(m);

        string s = "";
        for(int i = 0 ; i<n ; i++){
            s.push_back('.');
        }
        ans[m-1] = s;
        for(int i = m-2 ; i>=0 ; i--){
            string t = ".";
            for(int j = 1 ; j<n ; j++){
                t.push_back('#');
            }
            ans[i] = t;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna