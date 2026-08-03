class DSU {
private:
    vector<int> parent;
    vector<int> size_;
public:
    DSU(int n) {
        parent.resize(n);
        size_.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) return;
        if (size_[ru] < size_[rv]) {
            parent[ru] = rv;
            size_[rv] += size_[ru];
        } else {
            parent[rv] = ru;
            size_[ru] += size_[rv];
        }
    }

    int size(int u) {
        return size_[find(u)];
    }
};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);

        // Group point indices by x-coordinate, and by y-coordinate
        unordered_map<int, vector<int>> xGroups, yGroups;
        for (int i = 0; i < n; i++) {
            xGroups[points[i][0]].push_back(i);
            yGroups[points[i][1]].push_back(i);
        }

        // Union all points that share the same x
        for (auto& [x, idxs] : xGroups) {
            for (int i = 1; i < idxs.size(); i++) {
                dsu.unite(idxs[0], idxs[i]);
            }
        }

        // Union all points that share the same y
        for (auto& [y, idxs] : yGroups) {
            for (int i = 1; i < idxs.size(); i++) {
                dsu.unite(idxs[0], idxs[i]);
            }
        }

        // Now dsu.size(i) correctly = number of POINTS in that component
        unordered_set<int> seenRoots;
        int largest = 0, secondLargest = 0;

        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            if (seenRoots.count(root)) continue;
            seenRoots.insert(root);

            int sz = dsu.size(i);
            if (sz > largest) {
                secondLargest = largest;
                largest = sz;
            } else if (sz > secondLargest) {
                secondLargest = sz;
            }
        }

        if (seenRoots.size() == 1) {
            return largest + 1;
        }
        return largest + secondLargest + 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna