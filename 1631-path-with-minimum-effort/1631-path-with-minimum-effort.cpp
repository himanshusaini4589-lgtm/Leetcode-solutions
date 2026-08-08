class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<int>delr = {-1,0,1,0};
        vector<int>delc = {0,1,0,-1};

        vector<vector<int> >mini(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
        q.push({0,{0,0}});
        mini[0][0] = 0;
        int count = 1e9;
        while(!q.empty()){
            int dist = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            if(r==n-1 && c==m-1){
                count = min(dist,count);               
            }

            for(int i = 0 ; i<4 ; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m ){
                    int newDist = max(dist,abs(heights[r][c]-heights[nr][nc]));
                    if(newDist < mini[nr][nc]){
                        mini[nr][nc]  = newDist;
                        q.push({newDist,{nr,nc}});
                    }
                }
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna