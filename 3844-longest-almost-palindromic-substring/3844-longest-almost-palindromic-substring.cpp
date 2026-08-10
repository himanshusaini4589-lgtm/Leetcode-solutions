class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();

        auto expand = [&](int l, int r) {
            
            // Step 1: normal palindrome expansion
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }

            // First mismatch occurred at (l, r)

            // Option 1: delete s[l]
            int l1 = l - 1;
            int r1 = r;

            // Option 2: delete s[r]
            int l2 = l;
            int r2 = r + 1;

            // Continue expansion after deleting left character
            while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
                l1--;
                r1++;
            }

            // Continue expansion after deleting right character
            while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                l2--;
                r2++;
            }

            int option1 = r1 - l1 - 1;
            int option2 = r2 - l2 - 1;

            return min(n, max(option1, option2));
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Odd-length center
            ans = max(ans, expand(i, i));

            // Even-length center
            ans = max(ans, expand(i, i + 1));
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna