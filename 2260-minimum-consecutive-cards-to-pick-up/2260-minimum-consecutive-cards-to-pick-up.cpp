class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();

        map<int,int>v;

        int min_len = INT_MAX;

        for(int r = 0 ; r<n ; r++){
            if(v.count(cards[r])){
                min_len = min(r-v[cards[r]] + 1,min_len);
            }
            v[cards[r]] = r;
        }
        return min_len==INT_MAX ? -1 : min_len;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna