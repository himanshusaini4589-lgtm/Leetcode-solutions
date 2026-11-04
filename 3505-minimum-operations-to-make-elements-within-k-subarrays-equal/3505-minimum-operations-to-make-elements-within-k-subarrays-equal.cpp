class Solution {
public:
    int n;
    vector<long long> mini;
    vector<vector<long long>> dp;

    multiset<int> st1, st2;
    long long sum1 = 0, sum2 = 0;

    void balance() {
        while(st1.size() > st2.size() + 1) {
            int val = *st1.rbegin();

            st1.erase(prev(st1.end()));
            sum1 -= val;

            st2.insert(val);
            sum2 += val;
        }

        while(st1.size() < st2.size()) {
            int val = *st2.begin();

            st2.erase(st2.begin());
            sum2 -= val;

            st1.insert(val);
            sum1 += val;
        }
    }

    void insert(int val) {
        if(st1.empty() || val <= *st1.rbegin()) {
            st1.insert(val);
            sum1 += val;
        }
        else {
            st2.insert(val);
            sum2 += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = st1.find(val);

        if(it != st1.end()) {
            st1.erase(it);
            sum1 -= val;
        }
        else {
            it = st2.find(val);
            st2.erase(it);
            sum2 -= val;
        }

        balance();
    }

    long long getCost(int x) {
        long long med = *st1.rbegin();

        long long left = med * st1.size() - sum1;
        long long right = sum2 - med * st2.size();

        return left + right;
    }

    long long f(int i, int cnt, int x, int k) {

        if(cnt == k) return 0;

        if(i >= mini.size()) return LLONG_MAX / 2;

        if(dp[i][cnt] != -1) return dp[i][cnt];

        // Skip current window
        long long skip = f(i + 1, cnt, x, k);

        // Take current window
        long long take = mini[i] + f(i + x, cnt + 1, x, k);

        return dp[i][cnt] = min(take, skip);
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        n = nums.size();

        // Calculate cost of every window
        for(int i = 0; i < x; i++) {
            insert(nums[i]);
        }

        mini.push_back(getCost(x));

        for(int i = x; i < n; i++) {

            remove(nums[i-x]);

            insert(nums[i]);

            mini.push_back(getCost(x));
        }

        int m = mini.size();

        dp.assign(m + 1, vector<long long>(k + 1, -1));

        return f(0, 0, x, k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna