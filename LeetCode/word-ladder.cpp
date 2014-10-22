class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        map<string, int> dists;
        dists[start] = 1;
        dict.erase(start);
        dict.erase(end);
        dict.insert(end);
        for (auto s : dict) {
            dists[s] = 0;
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
                            if (dists[v] == 0 || dists[v] == dists[u] + 1) {
                                next[u].push_back(v);
                                if (dists[v] == 0) {
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
        return dists[end];
    }
};
