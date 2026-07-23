class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i = 0 ; i<n ; i++){
            mp[s[i]]++;
        }
        string t = "";
        bool flag;
        vector<int>ans;
        set<char>st;
        for(int i = 0 ; i<n ; i++){
            char ch = s[i];
            t.push_back(ch);
                mp[ch]--;
                st.insert(ch);
                if(mp[ch]==0){
                    mp.erase(ch);
                }
            flag = false;
            for(auto ele : st){
                if(mp.find(ele)!=mp.end()){
                    flag = true;
                }
            }
            if(!flag){
                ans.push_back(t.length());
                t = "";
                st.clear();
            }
                
        } 
        
        // set<char>st;
        // for(auto ele : t){
        //     st.insert(ele);
        // }
        // flag = false;
        // for(auto ele : st){
        //     if(mp.find(ele)!=mp.end()){
        //         flag = true;
        //     }
        // }
        // if(!flag){
        //     ans.push_back(t.length());
        //     t = "";
        // }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna