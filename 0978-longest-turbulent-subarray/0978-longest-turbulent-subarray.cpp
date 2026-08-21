class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return 1;

        int l = 0;
        int maxlen = 1;

        for (int r = 1; r < n; r++) {

            if (arr[r] == arr[r - 1]) {
                l = r;
            }
            else if (r == 1 ||
                     (arr[r] > arr[r - 1] && arr[r - 1] < arr[r - 2]) ||
                     (arr[r] < arr[r - 1] && arr[r - 1] > arr[r - 2])) {

                maxlen = max(maxlen, r - l + 1);
            }
            else {
                l = r - 1;
                maxlen = max(maxlen, r - l + 1);
            }
        }

        return maxlen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna