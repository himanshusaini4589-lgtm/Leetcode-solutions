class Solution {
public:

    vector<pair<int,int> > dr = {{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int r ,int c ,int n ,int m){
        return r>=0 && c>=0 && r<n && c<m;
    }
    int min_cost = INT_MAX;
    void dfs(vector<vector<int> >& grid,vector<vector<bool> > &vis,int cost,int r,int c,int n,int m){
        if(cost>= min_cost) return ;
        if(r == n-1 && c == m-1){
            min_cost = min(min_cost,cost);
            return ;
        }
        vis[r][c] = true;

        for(int i = 0 ; i<4 ; i++){
            auto ele = dr[i];
            int new_r = r + ele.first;
            int new_c = c + ele.second;
            if(!check(new_r,new_c,n,m) || vis[new_r][new_c]) continue;
            int direction = ((grid[r][c] == i+1) ? 0 : 1);
            int new_cost = direction + cost;
            dfs(grid,vis,new_cost,new_r,new_c,n,m);
        }

        vis[r][c] = false;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool> > vis(n,vector<bool>(m,false));
        dfs(grid,vis,0,0,0,n,m);
        return min_cost;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna