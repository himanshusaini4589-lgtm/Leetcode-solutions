class Solution {
public:
    vector<int> spf;

    void make_spf(int limit) {
        spf.resize(limit + 1);
        iota(spf.begin(), spf.end(), 0);

        for (int i = 4; i <= limit; i += 2) {
            spf[i] = 2;
        }

        for (int i = 3; i * i <= limit; i += 2) {
            if (spf[i] == i) {
                for (int j = 2* i; j <= limit; j +=  i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    vector<int> get_primes(int n) {
        vector<int> primes;

        while (n > 1) {
            primes.push_back(spf[n]);
            n /= spf[n];
        }

        sort(primes.begin(), primes.end());
        primes.erase(unique(primes.begin(), primes.end()), primes.end());

        return primes;
    }

    vector<int> get_subsets(int n) {
        vector<int> primes = get_primes(n);

        int m = primes.size();
        vector<int> subs(1 << m, 0);

        for (int i = 0; i < (1 << m); i++) {
            int val = 1;

            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    val *= primes[j];
                }
            }

            subs[i] = val;
        }

        return subs;
    }

    int maxScore(vector<int>& nums, int maxVal) {
        int mx = max(*max_element(nums.begin(), nums.end()), maxVal) + 1;

        make_spf(100000);

        vector<int> freq(mx, 0);

        for (int x : nums) {
            freq[x]++;
        }

        vector<int> mults = freq;

        for (int i = 2; i < mx; i++) {
            for (int j = 2 * i; j < mx; j += i) {
                mults[i] += freq[j];
            }
        }

        int ans = (freq[1] > 0 ? 1 : 0);

        for (int i = mx - 1; i >= 2; i--) {

            if (ans >= i) {
                break;
            }

            vector<int> subs = get_subsets(i);

            int rem = -freq[i];

            for (int j = 1; j < (int)subs.size(); j++) {

                if (__builtin_popcount(j) & 1) {
                    rem += mults[subs[j]];
                }
                else {
                    rem -= mults[subs[j]];
                }
            }

            if (freq[i] > 0) {
                int cost = rem + freq[i] - 1;
                ans = max(ans, i - cost);
            }
            else if (i <= maxVal) {
                int cost = (rem > 0 ? rem : 1);
                ans = max(ans, i - cost);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna