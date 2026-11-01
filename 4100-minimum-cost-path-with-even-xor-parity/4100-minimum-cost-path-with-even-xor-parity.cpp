class Solution {
public:
    long long ans = LLONG_MAX;
    // void dfs(int node,int parent ,int xr ,int start,long long cost,vector<pair<int,int> > adj[], vector<int>& values){
    //     if(node>start){
    //         if(__builtin_popcount(xr)%2==0){
    //             ans = min(ans,cost);
    //         }
    //     }
    //         for(auto [it , wt] : adj[node]){
    //             if(it== parent) continue;
    //             dfs(it,node,xr^values[it],start,cost + wt ,adj,values);
    //         }
        
    // }
    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {
        vector<pair<int,int> >adj[values.size()];
        int n = values.size();
        for(int i = 0 ; i<n ; i++){
            int value = values[i];
            values[i] = __builtin_popcount(value)%2;
        }
        for(int i = 0 ; i< edges.size() ; i++){
            auto ele = edges[i];
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
            if(values[ele[0]] == values[ele[1]]){
                ans = min(ans,(long long)ele[2]);
            }
        }
        // for(int i = 0; i<n ; i++){
        //     dfs(i,-1,values[i],i,0,adj,values);
        // }
        
        for(int i  = 0 ; i< n;  i++){
            if(values[i]){
                continue;
            }
            long long wt1 =  LLONG_MAX,wt2 = LLONG_MAX;
            for(auto [it,w] : adj[i]){
                if(values[it]){
                    
                    if(wt2 > w){
                        wt2 = w;
                    }
                    if(wt1 > wt2){
                       swap(wt1,wt2);
                    } 
                }
            }
            if(wt2<LLONG_MAX){
                ans = min(ans,wt1+wt2);
            }
        }
        
        if(ans == LLONG_MAX) return -1;
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna