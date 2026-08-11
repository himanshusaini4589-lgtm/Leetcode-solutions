class Solution {
public:

    vector<long long> mergeAdjacent(vector<int>& nums) {

        stack<long long> st;

        for (long long x : nums) {

            if (!st.empty() && st.top() == x) {
                st.pop();
                x *= 2;

                // Keep checking because the newly
                // created value may also merge.
                while (!st.empty() && st.top() == x) {
                    st.pop();
                    x *= 2;
                }
            }

            st.push(x);
        }

        vector<long long> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna