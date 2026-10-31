class Solution {
public:
    string ans = "";
    int cnt = 0;

    void f(int n, int k, vector<bool>& vis, string& temp) {

        if(temp.size() == n) {
            cnt++;

            if(cnt == k) {
                ans = temp;
            }

            return;
        }

        for(int i = 1; i <= n; i++) {

            if(!vis[i]) {

                vis[i] = true;
                temp.push_back(i + '0');

                f(n, k, vis, temp);

                temp.pop_back();
                vis[i] = false;

                if(ans != "") return;
            }
        }
    }

    string getPermutation(int n, int k) {

        vector<bool> vis(n+1, false);
        string temp = "";

        f(n, k, vis, temp);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna