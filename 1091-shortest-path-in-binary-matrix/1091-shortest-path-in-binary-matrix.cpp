class Solution {
public:
    vector<int> delr = {-1,-1,-1,0,1,1,1,0};
    vector<int> delc = {-1,0,1,1,1,0,-1,-1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        
        vector<vector<int> > dis(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>  ,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>> >> pq;
        pq.push({1,{0,0}});
        dis[0][0] = 1;
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int r = ele.second.first;
            int c = ele.second.second;
            int currdis = ele.first;
            for(int i = 0 ;i<8 ; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr>=0 && nr<n && nc >=0 && nc<n && grid[nr][nc]==0){
                    int newdist = currdis + 1;
                    if(dis[nr][nc]>newdist){
                        dis[nr][nc] = newdist;
                        pq.push({newdist,{nr,nc}});
                    }
                }
            }
        }
        if(dis[n-1][n-1] == INT_MAX) return -1;
        return dis[n-1][n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna