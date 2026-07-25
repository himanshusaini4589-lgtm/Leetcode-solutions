class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        vector<int>v1;
        vector<int>v2;
        for(int i = 0 ; i<n ; i++){
            v1.push_back(s1[i]-'a');
            v2.push_back(s2[i]-'a');
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        bool flag1 = true;
        bool flag2 = true;
        for(int i = 0 ;i<n ; i++){
            if(v1[i]<v2[i]){
                flag1 = false;
                break;
            }
        }
        for(int i = 0 ;i<n ; i++){
            if(v1[i]>v2[i]){
                flag2 = false;
                break;
            }
        }
        
        if(flag1 || flag2) return true;
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna