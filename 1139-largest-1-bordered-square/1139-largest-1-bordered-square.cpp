class Solution {
public:
    int n, m;
    vector<vector<int>> grid;
    vector<vector<int>> rightDP, downDP;

    int getRight(int i, int j) {
        if(i >= n || j >= m || grid[i][j] == 0)
            return 0;

        if(rightDP[i][j] != -1)
            return rightDP[i][j];

        return rightDP[i][j] = 1 + getRight(i, j + 1);
    }

    int getDown(int i, int j) {
        if(i >= n || j >= m || grid[i][j] == 0)
            return 0;

        if(downDP[i][j] != -1)
            return downDP[i][j];

        return downDP[i][j] = 1 + getDown(i + 1, j);
    }

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        this->grid = grid;

        n = grid.size();
        m = grid[0].size();

        rightDP.resize(n, vector<int>(m, -1));
        downDP.resize(n, vector<int>(m, -1));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 0)
                    continue;

                int maxLen = min(getRight(i, j), getDown(i, j));

                for(int len = maxLen; len >0; len--) {

                    // bottom border
                    if(getRight(i + len - 1, j) < len)
                        continue;

                    // right border
                    if(getDown(i, j + len - 1) < len)
                        continue;

                    ans  = max(ans,len);
                    break;
                }
            }
        }

        return ans * ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna