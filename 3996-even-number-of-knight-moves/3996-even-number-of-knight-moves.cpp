class Solution {
public:
    vector<pair<int,int>> dir = {
        {-2,-1}, {-2,1},
        {-1,-2}, {-1,2},
        {1,-2}, {1,2},
        {2,-1}, {2,1}
    };

    bool canReach(vector<int>& start, vector<int>& target) {

        queue<tuple<int,int,int>> q;
        // row, col, parity

        vector<vector<vector<int>>> vis(
            8, vector<vector<int>>(8, vector<int>(2, 0))
        );

        q.push({start[0], start[1], 0}); // 0 moves => even parity
        vis[start[0]][start[1]][0] = 1;

        while (!q.empty()) {
            auto [r, c, parity] = q.front();
            q.pop();

            if (r == target[0] && c == target[1] && parity == 0)
                return true;

            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < 8 &&
                    nc >= 0 && nc < 8) {

                    int np = parity ^ 1; // parity flips after every move

                    if (!vis[nr][nc][np]) {
                        vis[nr][nc][np] = 1;
                        q.push({nr, nc, np});
                    }
                }
            }
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna