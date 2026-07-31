class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();

        // Prefix Sum
        vector<int> B(n + 1, 0);
        for (int i = 0; i < n; i++)
            B[i + 1] = B[i] + (s[i] == '1' ? 1 : -1);

        int firstOne = -1, lastOne = -1;
        int firstZero = -1, lastZero = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (firstOne == -1) firstOne = i;
                lastOne = i;
            } else {
                if (firstZero == -1) firstZero = i;
                lastZero = i;
            }
        }

        // ---------------- Baseline ----------------
        int baseline = 0;
        {
            unordered_map<int, int> occ;

            for (int k = 0; k <= n; k++) {
                if (occ.count(B[k]))
                    baseline = max(baseline, k - occ[B[k]]);
                else
                    occ[B[k]] = k;
            }
        }

        // ---------------- Case A ----------------
        int ansA = 0;
        {
            unordered_map<int, int> occ;

            for (int k = 0; k <= n; k++) {

                if (k <= lastOne && occ.count(B[k] + 2))
                    ansA = max(ansA, k - occ[B[k] + 2]);

                if (!occ.count(B[k]))
                    occ[B[k]] = k;
            }
        }

        // ---------------- Case A' ----------------
        int ansA2 = 0;
        if (firstOne != -1) {

            unordered_map<int, int> occ;

            for (int k = n; k >= 0; k--) {

                if (k > firstOne && occ.count(B[k] - 2))
                    ansA2 = max(ansA2, occ[B[k] - 2] - k);

                if (!occ.count(B[k]))
                    occ[B[k]] = k;
            }
        }

        // ---------------- Case B ----------------
        int ansB = 0;
        {
            unordered_map<int, int> occ;

            for (int k = 0; k <= n; k++) {

                if (k <= lastZero && occ.count(B[k] - 2))
                    ansB = max(ansB, k - occ[B[k] - 2]);

                if (!occ.count(B[k]))
                    occ[B[k]] = k;
            }
        }

        // ---------------- Case B' ----------------
        int ansB2 = 0;
        if (firstZero != -1) {

            unordered_map<int, int> occ;

            for (int k = n; k >= 0; k--) {

                if (k > firstZero && occ.count(B[k] + 2))
                    ansB2 = max(ansB2, occ[B[k] + 2] - k);

                if (!occ.count(B[k]))
                    occ[B[k]] = k;
            }
        }

        return max({baseline, ansA, ansA2, ansB, ansB2});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna