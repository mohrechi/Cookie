class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> links;
        for (auto it : tickets) {
            links[it.first].insert(it.second);
        }
        vector<string> path;
        dfs("JFK", links, path);
        reverse(path.begin(), path.end());
        return path;
    }
    
    void dfs(const string& u, unordered_map<string, multiset<string>>& links, vector<string>& path) {
        while (links[u].size()) {
            string v = *links[u].begin();
            links[u].erase(links[u].begin());
            dfs(v, links, path);
        }
        path.push_back(u);
    }
};
