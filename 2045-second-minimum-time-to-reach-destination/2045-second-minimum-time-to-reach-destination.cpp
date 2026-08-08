class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<int>adj[n+1];

        for(int i = 0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<vector<int> > dist(n+1,vector<int>(2,INT_MAX));
        queue<pair<int,int>> pq;
        pq.push({0,1}); //{distance,node}

        dist[1][0] = 0;

        while(!pq.empty()){
            auto [dis , node] = pq.front();
            pq.pop();

            for(int el : adj[node]){
                int d = dis+1;
                if(d<dist[el][0]){
                    dist[el][0] = d;
                    pq.push({d,el});
                }
                else if(d>dist[el][0] && d<dist[el][1]){
                    dist[el][1] = d;
                    pq.push({d,el});
                }
            }
        }
        
        int freq = dist[n][1];
        int total_time = 0;
        for(int i = 0 ;i<freq ; i++){
            if((total_time/change)%2==1){
                total_time = (total_time/change+1)*change;
            }
            total_time += time;
        }

        return total_time;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna