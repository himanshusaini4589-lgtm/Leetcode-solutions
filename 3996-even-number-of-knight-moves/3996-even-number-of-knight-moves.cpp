class Solution {
public:
    vector<pair<int,int>> dir = {
        {-2,-1}, {-2,1},
        {-1,-2}, {-1,2},
        {1,-2}, {1,2},
        {2,-1}, {2,1}
    };

    bool dfs(int r, int c, int parity,
             vector<int>& target,
             vector<vector<vector<int>>>& vis) {

        if (r == target[0] && c == target[1] && parity == 0)
            return true;

        vis[r][c][parity] = 1;

        for (auto [dr, dc] : dir) {
            int nr = r + dr;
            int nc = c + dc;
            int np = parity ^ 1;

            if (nr >= 0 && nr < 8 &&
                nc >= 0 && nc < 8 &&
                !vis[nr][nc][np]) {

                if (dfs(nr, nc, np, target, vis))
                    return true;
            }
        }

        return false;
    }

    bool canReach(vector<int>& start, vector<int>& target) {
        vector<vector<vector<int>>> vis(
            8, vector<vector<int>>(8, vector<int>(2, 0))
        );

        return dfs(start[0], start[1], 0, target, vis);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna