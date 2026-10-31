
class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[501][501][2];
    int f(vector<vector<int>>& nums, int i, int j,
          int n, int m, int dir) {

        if(i >= n || j >= m) return 0;

        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        // Current cell is a mirror
        if(nums[i][j] == 1) {

            if(dir == 0) {
                return dp[i][j][dir] = f(nums, i+1, j, n, m, 1);
            }
            else {
                return dp[i][j][dir] = f(nums, i, j+1, n, m, 0);
            }
        }

        int count = 0;

        // Move right
        count += f(nums, i, j+1, n, m, 0);

        // Move down
        count += f(nums, i+1, j, n, m, 1);

        return dp[i][j][dir] = count % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return f(grid, 0, 0, n, m, 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna