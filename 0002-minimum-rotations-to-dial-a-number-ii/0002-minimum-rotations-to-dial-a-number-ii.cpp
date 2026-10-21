class Solution {
public:
    string reverse(string &s) {
        string ne = "";
        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            ne.push_back(s[i]);
        }

        return ne;
    }

    int minRotations(int n, string s) {
        int cnt = 0;
        int initial = 0;

        for (int i = 0; i < n; i++) {
            int t = s[i] - '0';
            cnt += min(abs(t - initial), 10 - abs(t - initial));
            initial = t;
        }

        int ans = cnt;

        for (int i = 0; i < n; i++) {
            int prev = (i == 0) ? 0 : s[i - 1] - '0';
            int last = s[n - 1] - '0';
            int curr = s[i] - '0';

            int oldCost = min(abs(curr - prev), 10 - abs(curr - prev));
            int newCost = min(abs(last - prev), 10 - abs(last - prev));

            ans = min(ans, cnt - oldCost + newCost);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna