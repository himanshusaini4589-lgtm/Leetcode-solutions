class Solution {
public:
    vector<int> tree, lazy;
    
    void build(int node, int start, int end) {
        tree[node] = 0;
    }
    
    void pushDown(int node) {
        if (lazy[node] != 0) {
            for (int child : {2*node, 2*node+1}) {
                tree[child] = max(tree[child], lazy[node]);
                lazy[child] = max(lazy[child], lazy[node]);
            }
            lazy[node] = 0;
        }
    }
    
    void update(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;              // no overlap
        if (l <= start && end <= r) {                   // fully covered
            tree[node] = max(tree[node], val);
            lazy[node] = max(lazy[node], val);
            return;
        }
        pushDown(node);
        int mid = (start + end) / 2;
        update(2*node, start, mid, l, r, val);
        update(2*node+1, mid+1, end, l, r, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;              // no overlap
        if (l <= start && end <= r) return tree[node];   // fully covered
        pushDown(node);
        int mid = (start + end) / 2;
        return max(query(2*node, start, mid, l, r),
                    query(2*node+1, mid+1, end, l, r));
    }
    
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        
        // Step 1: Coordinate compression
        vector<int> coords;
        for (auto& p : positions) {
            coords.push_back(p[0]);              // left
            coords.push_back(p[0] + p[1]);        // right
        }
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
        
        int m = coords.size();
        tree.assign(4 * m, 0);
        lazy.assign(4 * m, 0);
        
        vector<int> ans;
        int runningMax = 0;
        
        for (int i = 0; i < n; i++) {
            int left = positions[i][0];
            int right = left + positions[i][1];
            int side = positions[i][1];
            
            // map to compressed indices
            int l_idx = lower_bound(coords.begin(), coords.end(), left) - coords.begin();
            int r_idx = lower_bound(coords.begin(), coords.end(), right) - coords.begin();
            
            // query max height in [l_idx, r_idx - 1] (right is exclusive, so stop before it)
            int base = query(1, 0, m-1, l_idx, r_idx - 1);
            int newHeight = base + side;
            
            // update that range to newHeight
            update(1, 0, m-1, l_idx, r_idx - 1, newHeight);
            
            runningMax = max(runningMax, newHeight);
            ans.push_back(runningMax);
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna