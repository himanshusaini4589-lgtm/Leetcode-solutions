class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        int z = count(s.begin(),s.end(),'0');

        vector<int>pos;
        for(int i = 0 ; i<n ; i++){
            if(s[i]=='0') pos.push_back(i);
        }

        vector<bool>ans;
        for(auto t : strs){
            int zt = count(t.begin(),t.end(),'0');
            int questions = count(t.begin(),t.end(),'?');

            if(z>zt+questions || zt>z){
                ans.push_back(false);
                continue;
            }

            int rem = z-zt;
            for(auto &x : t){
                if(x=='?'){
                    if(rem){
                        x = '0';
                        rem--;
                    } 
                    else x  = '1';
                }
            }

            vector<int> v;
            for(int i = 0 ; i<t.length(); i++){
                if(t[i]=='0') v.push_back(i);
            }

            bool ok = true;
            for(int i = 0 ; i<v.size() ; i++){
                if(pos[i]<v[i]){
                    ok = false;
                    break;
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna