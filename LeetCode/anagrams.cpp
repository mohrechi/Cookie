class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<Node> nodes;
        for (int i = 0; i < strs.size(); ++i) {
            nodes.push_back({i, strs[i]});
            sort(nodes[i].str.begin(), nodes[i].str.end());
        }
        sort(nodes.begin(), nodes.end());
        vector<string> rets;
        for (int i = 0; i < nodes.size(); ++i) {
            bool flag = false;
            if (i > 0) {
                if (nodes[i].str == nodes[i - 1].str) {
                    flag = true;
                }
            }
            if (i < nodes.size() - 1) {
                if (nodes[i].str == nodes[i + 1].str) {
                    flag = true;
                }
            }
            if (flag) {
                rets.push_back(strs[nodes[i].index]);
            }
        }
        return rets;
    }
private:
    struct Node {
        int index;
        string str;
        bool operator <(const Node &node) const {
            return str < node.str;
        }
    };
};
