class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int,int>> dir = {
            {0,1},    
            {0,-1},  
            {1,0},  
            {-1,0}   
        };

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});   // {cost, row, col}

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0];
            int r = curr[1];
            int c = curr[2];
            if(cost > dist[r][c]) continue;
            if(r == n - 1 && c == m - 1) return cost;

            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int wt = (grid[r][c] == i + 1) ? 0 : 1;

                if(cost + wt < dist[nr][nc]) {
                    dist[nr][nc] = cost + wt;
                    pq.push({dist[nr][nc], nr, nc});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna