class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> deg(n, 0), indeg(n, 0);


        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            if (colors[i] == 'R') c[i] = 0;
            else if (colors[i] == 'B') c[i] = 1;
            else c[i] = 2;
        }

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            deg[u]++;
            deg[v]++;

            if ((c[u] + 1) % 3 == c[v]) indeg[v]++;       // u -> v
            else if ((c[v] + 1) % 3 == c[u]) indeg[u]++;  // v -> u
            else return -1;                               // same color
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                root = i;
            }
            if (indeg[i] > 1) return -1;     // two parents
        }

        if (root == -1) return -1;
        if (deg[root] > 2) return -1;

        for (int i = 0; i < n; i++) {
            if (i != root && deg[i] > 3) return -1;
        }

        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna