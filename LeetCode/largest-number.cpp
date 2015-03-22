class Solution {
public:
    struct Node {
        string val;
        
        Node(int x) {
            do {
                val = (char)(x % 10 + '0') + val;
                x /= 10;
            } while (x);
        }
        
        bool operator <(const Node& node) const {
            return val + node.val > node.val + val;
        }
    };

    string largestNumber(vector<int> &num) {
        vector<Node> nodes;
        for (auto n : num) {
            nodes.push_back(Node(n));
        }
        sort(nodes.begin(), nodes.end());
        string largest;
        for (auto node : nodes) {
            largest += node.val;
        }
        while (largest.length() > 1 && largest[0] == '0') {
            largest = largest.substr(1, largest.length() - 1);
        }
        return largest;
    }
};
