class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int>height(n,0);
        vector<pair<int,int> > v;
        vector<int>ans;
        int runningMax = 0;
        for(int i = 0 ; i<n ; i++){
            int left = positions[i][0];
            int right = left + positions[i][1];
            int hei = positions[i][1];

            int base = 0;
            for(int j = 0 ; j<i ; j++){
                int l = v[j].first;
                int r = v[j].second;

                if(l<right && left<r){
                    base = max(base,height[j]);
                }
            }
            height[i] = hei + base;
            v.push_back({left,right});
            runningMax = max(height[i],runningMax);
            ans.push_back(runningMax);

        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna