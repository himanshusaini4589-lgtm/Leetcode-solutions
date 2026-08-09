class Solution {
public:

    bool check(int mid,vector<vector<int>>&prefix){
        int n = prefix.size()-1;
        int m = prefix[0].size()-1;

        int minrow = n;
        int maxrow = -1;
        int mincol = m;
        int maxcol = -1;

        for(int i = 0 ; i<= n-mid ; i++){
            for(int j = 0 ; j<=m-mid ; j++){

                int sum = prefix[i+mid][j+mid] - prefix[i+mid][j] - prefix[i][j+mid] + prefix[i][j];

                if(sum!=mid*mid) continue;

                minrow = min(i,minrow);
                maxrow = max(i,maxrow);
                mincol = min(mincol,j);
                maxcol = max(maxcol,j);
                if(maxrow - minrow >= mid  ||  maxcol - mincol >= mid){
                    return true;
                }
            }
        }
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                prefix[i+1][j+1] = mat[i][j] + prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
            }
        }

        int lo = 1 ;
        int hi = max(n,m);
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            if(check(mid,prefix)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        return ans*ans;

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna