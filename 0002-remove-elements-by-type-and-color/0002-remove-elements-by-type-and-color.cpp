class Solution {
public:

    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& g) {
        int n = colors.size();

        stack<array<int,3> > st;
        int cnt = 1;

        for(int i = 1 ; i<n ; i++){
            if((types[i] != types[i-1]) || (colors[i] != colors[i-1])){
                if(cnt%g[types[i-1]] != 0){
                    st.push({types[i-1],colors[i-1],cnt%g[types[i-1]]});
                    cnt = 1;
                }
                else{
                    if(!st.empty() && types[i] == st.top()[0] && colors[i] == st.top()[1]){
                        cnt = 1 + st.top()[2];
                        st.pop();
                    }
                    else{
                        cnt = 1;
                    }
                }
            }
            else{
                cnt++;
            }
        }

        return cnt%g[types.back()] == 0 && st.empty();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna