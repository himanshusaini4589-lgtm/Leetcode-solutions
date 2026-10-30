class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<pair<int,int>> adj[n];

        for(int i = 0; i < edges.size(); i++) {
            auto ele = edges[i];
            adj[ele[0]].push_back({ele[1], ele[2]});
        }

        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;

        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        // {distance, consecutive count, node}
        pq.push({0, 1, 0});
        dist[0][1] = 0;

        while(!pq.empty()) {

            auto ele = pq.top();
            pq.pop();

            int d = ele[0];
            int cnt = ele[1];
            int node = ele[2];

            if(d > dist[node][cnt]) continue;

            if(node == n - 1) return d;

            for(auto [next, wt] : adj[node]) {

                int r = (labels[next] == labels[node]) ? cnt + 1 : 1;

                if(r > k) continue;

                if(d + wt < dist[next][r]) {

                    dist[next][r] = d + wt;

                    pq.push({d + wt, r, next});
                }
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna