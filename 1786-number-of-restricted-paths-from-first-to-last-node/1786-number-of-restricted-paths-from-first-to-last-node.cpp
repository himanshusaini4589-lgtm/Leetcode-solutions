class Solution {
public:
    int MOD = 1e9 + 7;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        if (n == 1) return 0;

        vector<vector<pair<int,int>>> graph(n + 1);   // {weight, neighbor}
        for (auto& e : edges) {
            graph[e[0]].push_back({e[2], e[1]});
            graph[e[1]].push_back({e[2], e[0]});
        }

        vector<int> dist = dijkstra(n, graph);
        vector<int> memo(n + 1, -1);
        return dfs(1, n, graph, dist, memo);
    }

    // Dijkstra: shortest distance from node `n` to every other node
    vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& graph) {
        vector<int> dist(n + 1, INT_MAX);
        dist[n] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, n});   // {dist, node}

        while (!minHeap.empty()) {
            int d = minHeap.top().first;
            int u = minHeap.top().second;
            minHeap.pop();
            if (d != dist[u]) continue;

            for (auto& nei : graph[u]) {
                int w = nei.first, v = nei.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    minHeap.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int dfs(int src, int n, vector<vector<pair<int,int>>>& graph, vector<int>& dist, vector<int>& memo) {
        if (memo[src] != -1) return memo[src];
        if (src == n) return 1;   // reached destination

        long long ans = 0;
        for (auto& nei : graph[src]) {
            int w = nei.first, v = nei.second;
            if (dist[src] > dist[v]) {
                ans = (ans + dfs(v, n, graph, dist, memo)) % MOD;
            }
        }
        return memo[src] = (int)ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna