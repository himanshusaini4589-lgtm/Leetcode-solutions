class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        vector<vector<int>> v;

        for(auto ele : logs) {
            v.push_back({ele[1], ele[0]});
        }

        sort(v.begin(), v.end());

        vector<vector<int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        int l = 0, r = 0;
        int active = 0;

        vector<int> cnt(n+1, 0);
        vector<int> ans(q.size());

        for(int i = 0; i < q.size(); i++) {

            int ranges = q[i][0] - x;
            int rangee = q[i][0];

            // Insert logs inside the right boundary
            while(r < v.size() && v[r][0] <= rangee) {

                int id = v[r][1];

                if(cnt[id] == 0) active++;

                cnt[id]++;
                r++;
            }

            // Remove logs outside the left boundary
            while(l < r && v[l][0] < ranges) {

                int id = v[l][1];

                cnt[id]--;

                if(cnt[id] == 0) active--;

                l++;
            }

            ans[q[i][1]] = n - active;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna