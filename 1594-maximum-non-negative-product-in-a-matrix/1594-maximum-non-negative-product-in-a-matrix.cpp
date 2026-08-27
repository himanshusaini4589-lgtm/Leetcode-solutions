class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const long long MOD = 1000000007;

        vector<vector<long long>> maxi(n, vector<long long>(m));
        vector<vector<long long>> mini(n, vector<long long>(m));

        maxi[n-1][m-1] = mini[n-1][m-1] = grid[n-1][m-1];

        // Last column — only one neighbor (below), never a "stop here" option
        for (int i = n-2; i >= 0; i--) {
            long long v = grid[i][m-1];
            if (v < 0) {
                maxi[i][m-1] = mini[i+1][m-1] * v;
                mini[i][m-1] = maxi[i+1][m-1] * v;
            } else {
                maxi[i][m-1] = maxi[i+1][m-1] * v;
                mini[i][m-1] = mini[i+1][m-1] * v;
            }
        }

        // Last row — only one neighbor (right)
        for (int j = m-2; j >= 0; j--) {
            long long v = grid[n-1][j];
            if (v < 0) {
                maxi[n-1][j] = mini[n-1][j+1] * v;
                mini[n-1][j] = maxi[n-1][j+1] * v;
            } else {
                maxi[n-1][j] = maxi[n-1][j+1] * v;
                mini[n-1][j] = mini[n-1][j+1] * v;
            }
        }

        // Interior cells — two neighbors, right and down
        for (int i = n-2; i >= 0; i--) {
            for (int j = m-2; j >= 0; j--) {
                long long v = grid[i][j];
                if (v >= 0) {
                    maxi[i][j] = v * max(maxi[i][j+1], maxi[i+1][j]);
                    mini[i][j] = v * min(mini[i][j+1], mini[i+1][j]);
                } else {
                    maxi[i][j] = v * min(mini[i][j+1], mini[i+1][j]);
                    mini[i][j] = v * max(maxi[i][j+1], maxi[i+1][j]);
                }
            }
        }

        return maxi[0][0] < 0 ? -1 : (int)(maxi[0][0] % MOD);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna