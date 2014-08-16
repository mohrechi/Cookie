/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return node;
        }
        origin.clear();
        nodes.clear();
        clone(node);
        for (auto n : nodes) {
            for (auto i : origin[n.second->label]->neighbors) {
                n.second->neighbors.push_back(nodes[i->label]);
            }
        }
        return nodes[node->label];
    }
private:
    map<int, UndirectedGraphNode*> origin;
    map<int, UndirectedGraphNode*> nodes;
    void clone(UndirectedGraphNode* node) {
        if (origin.find(node->label) != origin.end()) {
            return;
        }
        origin[node->label] = node;
        nodes[node->label] = new UndirectedGraphNode(node->label);
        for (auto n : node->neighbors) {
            clone(n);
        }
    }
};
