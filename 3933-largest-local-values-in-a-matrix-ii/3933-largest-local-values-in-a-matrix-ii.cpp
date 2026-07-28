class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<vector<int>>> pfx(
            201,
            vector<vector<int>>(n + 1, vector<int>(m + 1, 0))
        );

        // Build prefix sums
        for (int v = 0; v <= 200; v++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    pfx[v][i + 1][j + 1] =
                        pfx[v][i][j + 1]
                      + pfx[v][i + 1][j]
                      - pfx[v][i][j]
                      + (matrix[i][j] > v);

                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                int val = matrix[i][j];

                if (val == 0)
                    continue;

                int r1 = max(0, i - val);
                int r2 = min(n - 1, i + val);

                int c1 = max(0, j - val);
                int c2 = min(m - 1, j + val);

                int cnt =
                    pfx[val][r2 + 1][c2 + 1]
                  - pfx[val][r1][c2 + 1]
                  - pfx[val][r2 + 1][c1]
                  + pfx[val][r1][c1];

                int dr[4] = {-val, -val, val, val};
                int dc[4] = {-val, val, -val, val};

                for (int k = 0; k < 4; k++) {

                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        matrix[nr][nc] > val)
                        cnt--;
                }

                if (cnt == 0)
                    ans++;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna