class Solution {
public:

    // After deleting one character, continue expanding
    int expandAfterDelete(string &s, int l, int r) {

        int n = s.size();

        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        // Length of the substring covered
        return r - l - 1;
    }


    // Try one center
    int check(string &s, int l, int r) {

        int n = s.size();

        // Step 1: Normal palindrome expansion
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        // Now either:
        // 1. We went outside the string
        // 2. We found the first mismatch

        // Option 1: Delete s[l]
        int len1 = expandAfterDelete(s, l - 1, r);

        // Option 2: Delete s[r]
        int len2 = expandAfterDelete(s, l, r + 1);

        return min(n, max(len1, len2));
    }


    int almostPalindromic(string s) {

        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Odd length center
            ans = max(ans, check(s, i, i));

            // Even length center
            ans = max(ans, check(s, i, i + 1));
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna