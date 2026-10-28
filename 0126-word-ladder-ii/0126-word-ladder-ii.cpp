class Solution {
public:

    vector<vector<string> >ans;
    vector<string>path;
    unordered_map<string ,int> mpp;
    string beginWord;
    string endWord;
    void dfs(string s,int level){
        if(s == beginWord){
            vector<string> temp = path;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }

        for(int i = 0 ; i< s.size() ; i++){
            char oc = s[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    s[i] = ch;
                    if(mpp.count(s) && mpp[s]+1 == level){
                        path.push_back(s);
                        dfs(s,mpp[s]);
                        path.pop_back();
                    }
                }
                s[i] = oc;
        }

    }
    vector<vector<string>> findLadders(string begi, string end, vector<string>& wordList) {
        beginWord = begi ;
        endWord = end;
        mpp[beginWord] = 1;
        queue<pair<string ,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        path.push_back(endWord);
        q.push({beginWord,1});
        while(!q.empty()){
            auto [s, val]  = q.front();
            q.pop();

            for(int i = 0 ; i<s.size() ; i++){
                char oc = s[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    s[i] = ch;
                    if(st.count(s)){
                        mpp[s] = val + 1;
                        st.erase(s);
                        q.push({s,val+1});
                    }
                }
                s[i] = oc;
            }
        }
        dfs(endWord,mpp[endWord]);
        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna