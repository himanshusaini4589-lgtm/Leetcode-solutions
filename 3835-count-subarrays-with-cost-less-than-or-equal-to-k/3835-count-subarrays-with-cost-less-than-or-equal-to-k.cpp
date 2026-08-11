class Solution {
public:

    vector<long long> segMax, segMin;

    // Root node = 0
    void build(int node, int l, int r, vector<int>& nums) {

        if (l == r) {
            segMax[node] = nums[l];
            segMin[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node + 1, l, mid, nums);
        build(2 * node + 2, mid + 1, r, nums);

        segMax[node] = max(
            segMax[2 * node + 1],
            segMax[2 * node + 2]
        );

        segMin[node] = min(
            segMin[2 * node + 1],
            segMin[2 * node + 2]
        );
    }

    long long queryMax(
        int node,
        int l,
        int r,
        int ql,
        int qr
    ) {

        // Completely outside
        if (qr < l || r < ql)
            return LLONG_MIN;

        // Completely inside
        if (ql <= l && r <= qr)
            return segMax[node];

        int mid = (l + r) / 2;

        return max(
            queryMax(
                2 * node + 1,
                l,
                mid,
                ql,
                qr
            ),

            queryMax(
                2 * node + 2,
                mid + 1,
                r,
                ql,
                qr
            )
        );
    }

    long long queryMin(
        int node,
        int l,
        int r,
        int ql,
        int qr
    ) {

        // Completely outside
        if (qr < l || r < ql)
            return LLONG_MAX;

        // Completely inside
        if (ql <= l && r <= qr)
            return segMin[node];

        int mid = (l + r) / 2;

        return min(
            queryMin(
                2 * node + 1,
                l,
                mid,
                ql,
                qr
            ),

            queryMin(
                2 * node + 2,
                mid + 1,
                r,
                ql,
                qr
            )
        );
    }

    long long countSubarrays(
        vector<int>& nums,
        long long k
    ) {

        int n = nums.size();

        segMax.resize(4 * n);
        segMin.resize(4 * n);

        // Root starts from 0
        build(0, 0, n - 1, nums);

        int left = 0;
        long long ans = 0;

        for (int right = 0; right < n; right++) {

            while (left <= right) {

                long long mx = queryMax(
                    0,
                    0,
                    n - 1,
                    left,
                    right
                );

                long long mn = queryMin(
                    0,
                    0,
                    n - 1,
                    left,
                    right
                );

                long long len = right - left + 1;

                if ((mx - mn) * len <= k)
                    break;

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna