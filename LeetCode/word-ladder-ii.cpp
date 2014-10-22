class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, int> dists;
        dists[start] = 0;
        dict.erase(start);
        dict.erase(end);
        dict.insert(end);
        for (auto s : dict) {
            dists[s] = -1;
        }
        vector<string> q;
        q.push_back(start);
        map<string, vector<string>> next;
        int front = 0;
        while (front < q.size()) {
            string u = q[front];
            for (int i = 0; i < u.length(); ++i) {
                string v = u;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c != u[i]) {
                        v[i] = c;
                        if (dict.find(v) != dict.end()) {
                            if (dists[v] == -1 || dists[v] == dists[u] + 1) {
                                next[u].push_back(v);
                                if (dists[v] == -1) {
                                    q.push_back(v);
                                    dists[v] = dists[u] + 1;
                                }
                            }
                        }
                    }
                }
            }
            ++front;
        }
        vector<vector<string>> ret;
        vector<string> path;
        path.push_back(start);
        dfs(start, end, next, path, ret);
        return ret;
    }
private:
    void dfs(string &u, string &end, map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ret) {
        if (u == end) {
            ret.push_back(path);
            return;
        }
        for (auto v : next[u]) {
            path.push_back(v);
            dfs(v, end, next, path, ret);
            path.pop_back();
        }
    }
};
