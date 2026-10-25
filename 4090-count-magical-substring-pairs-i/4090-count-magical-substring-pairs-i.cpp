class Solution {
public:
    int countMagicalPairs(string s) {

        int n = s.length();
        vector<vector<int> > v(n,vector<int>(27,0));

        for(int i = 0 ; i<n ; i++){
            set<char>st;
            for(int j = i ; j>=0 ; j--){
                st.insert(s[j]);
                v[i][st.size()]++;
            }
        }

        int count = 0;
        for(int i = 1; i<n ; i++){
            set<char>st;
            for(int j = i ; j<n ; j++){
                st.insert(s[j]);
                count += v[i-1][st.size()];
            }
        }

        return count;































        // int n = s.size();
        // long long ans = 0;

        // for (int j = 0; j < n - 1; j++) {
        //     long long L[27] = {0}, R[27] = {0};

        //     // left: s[i..j], i goes j -> 0
        //     int seen[26] = {0}, d = 0;
        //     for (int i = j; i >= 0; i--) {
        //         if (seen[s[i] - 'a']++ == 0) d++;
        //         L[d]++;
        //     }

        //     // right: s[j+1..k], k goes j+1 -> n-1
        //     fill(seen, seen + 26, 0);
        //     d = 0;
        //     for (int k = j + 1; k < n; k++) {
        //         if (seen[s[k] - 'a']++ == 0) d++;
        //         R[d]++;
        //     }

        //     for (int c = 1; c <= 26; c++) ans += L[c] * R[c];
        // }
        // return (int)ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna