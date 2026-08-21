class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();

        int noDelete = arr[0];
        int oneDelete = -1e8;

        int ans = arr[0];

        for (int i = 1; i < n; i++) {

            int prevNoDelete = noDelete;
            int prevOneDelete = oneDelete;

            // Normal Kadane
            noDelete = max(arr[i],
                           prevNoDelete + arr[i]);

            // Either delete current element
            // OR deletion was already used
            oneDelete = max(prevNoDelete,
                            prevOneDelete + arr[i]);

            ans = max({ans, noDelete, oneDelete});
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna