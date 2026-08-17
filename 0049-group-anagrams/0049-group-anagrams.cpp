class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<pair<string,int>> str;
        for(int i = 0 ; i < n ; i++){
            str.push_back({strs[i],i});
        }
        
        for(int i = 0 ; i<n ; i++){
            string s = str[i].first;
            sort(s.begin(),s.end());
            str[i].first = s;
        }
        sort(str.begin(),str.end());

        vector<vector<string> >ans;

        int i = 0;

        for(auto el : str){
            vector<string>v;
            
            for(int ind = i ; ind<n ; ind++){
                if(el.first == str[ind].first){
                    int in = str[ind].second;
                    v.push_back(strs[in]);
                }
                else break;
                i++;    
            }
            if(v.size()) ans.push_back(v);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna