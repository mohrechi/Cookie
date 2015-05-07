class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> edges(numCourses);
        vector<int> in(numCourses);
        for (auto prerequisite : prerequisites) {
            edges[prerequisite[0]].insert(prerequisite[1]);
        }
        int currentTime = 0;
        vector<int> timestamp(numCourses, -1);
        vector<int> lowest(numCourses, -1);
        inStack = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (timestamp[i] == -1) {
                if (hasCycle(edges, timestamp, currentTime, lowest, i)) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    stack<int> stk;
    vector<bool> inStack;
    bool hasCycle(vector<set<int>>& edges, vector<int>& timestamp, int& currentTime, vector<int>& lowest, int u) {
        timestamp[u] = lowest[u] = currentTime++;
        inStack[u] = true;
        stk.push(u);
        for (auto v : edges[u]) {
            if (timestamp[v] == -1) {
                if (hasCycle(edges, timestamp, currentTime, lowest, v)) {
                    return true;
                }
                lowest[u] = min(lowest[u], lowest[v]);
            } else if (inStack[v]) {
                lowest[u] = min(lowest[u], timestamp[v]);
            }
        }
        int num = 0;
        if (lowest[u] == timestamp[u]) {
            int t;
            do {
                t = stk.top();
                stk.pop();
                inStack[t] = false;
                ++num;
            } while (t != u);

        }
        return num > 1;
    }
};