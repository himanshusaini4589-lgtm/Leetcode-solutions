class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";

        while (a > 0 || b > 0) {

            int n = ans.size();

            // If last two characters are same, force the other character
            if (n >= 2 && ans[n - 1] == ans[n - 2]) {
                if (ans[n - 1] == 'a') {
                    ans.push_back('b');
                    b--;
                } else {
                    ans.push_back('a');
                    a--;
                }
            }
            else {
                if (a >= b && a > 0) {
                    ans.push_back('a');
                    a--;
                } else {
                    ans.push_back('b');
                    b--;
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna