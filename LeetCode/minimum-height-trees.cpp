class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> links(n);
        for (auto& edge : edges) {
            links[edge.first].insert(edge.second);
            links[edge.second].insert(edge.first);
        }
        queue<int> q;
        vector<int> dist(n, -1);
        for (int i = 0; i < n; ++i) {
            if (links[i].size() <= 1U) {
                q.push(i);
                dist[i] = 0;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : links[u]) {
                links[v].erase(u);
                if (links[v].size() <= 1U) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        int maxDist = -1;
        vector<int> roots;
        for (int i = 0; i < n; ++i) {
            if (dist[i] > maxDist) {
                maxDist = dist[i];
                roots = vector<int>(1, i);
            } else if (dist[i] == maxDist) {
                roots.push_back(i);
            }
        }
        return roots;
    }
};
