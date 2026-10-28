class Solution {
public:
    vector<int> seg;
    int n;

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) {
            return 0;
        }

        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<int> coords = {0};

        for (auto& q : queries) {
            if (q[0] == 1) {
                coords.push_back(q[1]);
            }
        }

        sort(coords.begin(), coords.end());

        coords.erase(
            unique(coords.begin(), coords.end()),
            coords.end()
        );

        n = coords.size();
        seg.assign(4 * n + 5, 0);

        set<int> obstacles;
        obstacles.insert(0);

        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto it = obstacles.lower_bound(x);

                int nxt = -1;

                if (it != obstacles.end()) {
                    nxt = *it;
                }

                int pre = *prev(it);

                obstacles.insert(x);

                int idx = lower_bound(
                    coords.begin(), coords.end(), x
                ) - coords.begin();

                update(1, 0, n - 1, idx, x - pre);

                if (nxt != -1) {
                    int nextIdx = lower_bound(
                        coords.begin(), coords.end(), nxt
                    ) - coords.begin();

                    update(1, 0, n - 1, nextIdx, nxt - x);
                }
            }
            else {
                int x = q[1];
                int sz = q[2];

                int idx = upper_bound(
                    coords.begin(), coords.end(), x
                ) - coords.begin() - 1;

                int maxGap = query(1, 0, n - 1, 0, idx);

                auto it = obstacles.upper_bound(x);
                --it;

                int lastGap = x - *it;

                ans.push_back(max(maxGap, lastGap) >= sz);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna