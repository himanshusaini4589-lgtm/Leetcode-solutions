class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;

        q.push({beginWord,1});

        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        int ans = INT_MAX;
        while(!q.empty()){
            auto [s , val] = q.front();
            q.pop();

            if(s == endWord) ans = min(ans,val);

            for(int i = 0 ; i<s.size(); i++){
                char original = s[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    s[i] = ch;
                    if(st.find(s)!=st.end()){
                        q.push({s,val+1});
                        st.erase(s);
                    }
                }
                s[i] = original;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna