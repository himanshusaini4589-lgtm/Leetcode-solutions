class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> up, down, left, right;
    int n;

    int getUp(int r, int c) {
        if(r < 0 || grid[r][c] == 0)
            return 0;

        if(up[r][c] != -1)
            return up[r][c];

        return up[r][c] = 1 + getUp(r - 1, c);
    }

    int getDown(int r, int c) {
        if(r >= n || grid[r][c] == 0)
            return 0;

        if(down[r][c] != -1)
            return down[r][c];

        return down[r][c] = 1 + getDown(r + 1, c);
    }

    int getLeft(int r, int c) {
        if(c < 0 || grid[r][c] == 0)
            return 0;

        if(left[r][c] != -1)
            return left[r][c];

        return left[r][c] = 1 + getLeft(r, c - 1);
    }

    int getRight(int r, int c) {
        if(c >= n || grid[r][c] == 0)
            return 0;

        if(right[r][c] != -1)
            return right[r][c];

        return right[r][c] = 1 + getRight(r, c + 1);
    }

    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        n = N;

        grid.resize(n, vector<int>(n, 1));

        for(auto &mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }

        up.resize(n, vector<int>(n, -1));
        down.resize(n, vector<int>(n, -1));
        left.resize(n, vector<int>(n, -1));
        right.resize(n, vector<int>(n, -1));

        int ans = 0;

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0)
                    continue;

                int u = getUp(r, c);
                int d = getDown(r, c);
                int l = getLeft(r, c);
                int ri = getRight(r, c);

                int order = min({u, d, l, ri});

                ans = max(ans, order);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna