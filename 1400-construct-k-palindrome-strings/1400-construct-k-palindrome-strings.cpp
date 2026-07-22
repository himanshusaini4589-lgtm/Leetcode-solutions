class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size())
            return false;

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int odd = 0;

        for (int x : freq)
            if (x % 2)
                odd++;

        return odd <= k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna