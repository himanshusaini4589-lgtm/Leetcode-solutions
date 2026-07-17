class Solution {
public:
    vector<int> tree;
    int treeSize;
    
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] += val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) update(2*node+1, l, mid, idx, val);
        else update(2*node+2, mid+1, r, idx, val);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;              // no overlap
        if (ql <= l && r <= qr) return tree[node];    // fully covered
        int mid = l + (r - l) / 2;
        return query(2*node+1, l, mid, ql, qr) + query(2*node+2, mid+1, r, ql, qr);
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int sz = nums.size();
        vector<long long> prefix(sz + 1, 0);
        for (int i = 0; i < sz; i++) prefix[i+1] = prefix[i] + nums[i];
        
        // Step 1: coordinate compression
        // saare values jo tree mein kabhi insert ya query honge, collect karo
        vector<long long> allVals;
        for (auto p : prefix) {
            allVals.push_back(p);              // insert hoga
            allVals.push_back(p - lower);       // query boundary
            allVals.push_back(p - upper);       // query boundary
        }
        sort(allVals.begin(), allVals.end());
        allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());
        
        treeSize = allVals.size();
        tree.assign(4 * treeSize, 0);
        
        int count = 0;
        for (int j = 0; j <= sz; j++) {
            // query karo: kitne pehle wale prefix[i] hain jaha
            // prefix[j] - upper <= prefix[i] <= prefix[j] - lower
            long long loVal = prefix[j] - upper;
            long long hiVal = prefix[j] - lower;
            
            int loIdx = lower_bound(allVals.begin(), allVals.end(), loVal) - allVals.begin();
            int hiIdx = upper_bound(allVals.begin(), allVals.end(), hiVal) - allVals.begin() - 1;
            
            if (loIdx <= hiIdx) {
                count += query(0, 0, treeSize - 1, loIdx, hiIdx);
            }
            
            // ab current prefix[j] ko tree mein insert karo (future queries ke liye)
            int idx = lower_bound(allVals.begin(), allVals.end(), prefix[j]) - allVals.begin();
            update(0, 0, treeSize - 1, idx, 1);
        }
        
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna