class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        while (!pq.empty()) {
            auto [d, r, c] = pq.top(); pq.pop();

            if (d > dist[r][c]) continue;
            if (r == n-1 && c == n-1) return d;
            
            for (int i = 0; i < 4; i++) {
                int nr = r+dr[i], nc = c+dc[i];
                if (nr>=0 && nr<n && nc>=0 && nc<n) {
                    int nd = max(d, grid[nr][nc]);
                    if (nd < dist[nr][nc]) {
                        dist[nr][nc] = nd;
                        pq.push({nd, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna