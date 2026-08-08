class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dis(n,0);
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});

        vector<pair<int,double>>adj[n];
        for(int i = 0 ; i<edges.size() ; i++){
            auto ele = edges[i];
            adj[ele[0]].push_back({ele[1],succProb[i]});
            adj[ele[1]].push_back({ele[0],succProb[i]});
        }
        while(!pq.empty()){
            auto el = pq.top();
            double pro = el.first;
            int node = el.second;
            pq.pop();
            for(auto it : adj[node]){
                int ne = it.first;
                double prob = it.second;
                if(prob*pro>dis[ne]){
                    dis[ne] = prob*pro;
                    pq.push({prob*pro,ne});
                }
            }
        }
        return dis[end_node];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna