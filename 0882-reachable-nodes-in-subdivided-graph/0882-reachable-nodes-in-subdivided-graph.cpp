class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<int,int> > adj[n];
        for(int i = 0 ; i < edges.size() ; i++){
            auto ele = edges[i];
            int u = ele[0];
            int v = ele[1];
            int cnt = ele[2];
            adj[u].push_back({v,cnt});
            adj[v].push_back({u,cnt});
        }

        //applying standerd dijkstra
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if(w > dist[node])
                continue;

            for(auto el : adj[node]){
                int new_w = el.second + 1;
                int new_node = el.first;
                if(w + new_w < dist[new_node]){
                    dist[new_node] = new_w + w;
                    pq.push({new_w + w , new_node});
                }
            }
        }
        //if reachable 
        int count = 0;
        for(int i = 0 ; i< n ; i++){
            if(dist[i]<=maxMoves){
                count++;
            }
        }
        // new nodes
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            int u_d = dist[u] < maxMoves ? maxMoves - dist[u] : 0;
            int v_d = dist[v] < maxMoves ? maxMoves - dist[v] : 0;

            count += min(cnt,u_d + v_d);
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna