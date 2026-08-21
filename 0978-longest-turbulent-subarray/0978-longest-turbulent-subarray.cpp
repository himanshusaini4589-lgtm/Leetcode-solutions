class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int n = arr.size();

        if (n == 1)
            return 1;

        int len = 1;
        int ans = 1;

        int prevSign = 0;

        for (int i = 1; i < n; i++) {

            int currSign = 0;

            if (arr[i] > arr[i - 1])
                currSign = 1;
            else if (arr[i] < arr[i - 1])
                currSign = -1;

            if (currSign == 0) {
                // equal elements
                len = 1;
            }
            else if (prevSign == 0 || currSign != prevSign) {
                // alternate -> extend
                len++;
            }
            else {
                // same sign -> restart
                len = 2;
            }

            ans = max(ans, len);

            prevSign = currSign;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna