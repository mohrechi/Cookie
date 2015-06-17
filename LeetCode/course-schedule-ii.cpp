class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> next(numCourses);
        for (auto prerequisite : prerequisites) {
            int second = prerequisite.first;
            int first = prerequisite.second;
            next[first].push_back(second);
            ++in[second];
        }
        vector<int> order;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) {
                order.push_back(i);
            }
        }
        for (int i = 0; i < (int)order.size(); ++i) {
            for (int j = 0; j < (int)next[order[i]].size(); ++j) {
                if (--in[next[order[i]][j]] == 0) {
                    order.push_back(next[order[i]][j]);
                }
            }
        }
        if ((int)order.size() < numCourses) {
            order.clear();
        }
        return order;
    }
};