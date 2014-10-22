class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<Node> triplets;
        for (int k = 2; k < nums.size(); ++k) {
            int front = 0, rear = k - 1;
            while (front < rear) {
                int temp = nums[front] + nums[rear];
                if (temp == -nums[k]) {
                    triplets.push_back(Node(nums[front], nums[rear], nums[k]));
                    ++front;
                } else if (temp < -nums[k]) {
                    ++front;
                } else {
                    --rear;
                }
            }
        }
        vector<vector<int> > ret;
        if (triplets.size() > 0) {
            sort(triplets.begin(), triplets.end());
            ret.push_back(triplets[0].toTriplet());
        }
        for (int i = 1; i < triplets.size(); ++i) {
            if (triplets[i] != triplets[i - 1]) {
                ret.push_back(triplets[i].toTriplet());
            }
        }
        return ret;
    }
private:
    struct Node {
        int a, b, c;
        Node(int _a, int _b, int _c) {
            a = _a, b = _b, c = _c;
        }
        bool operator <(const Node &node) const {
            if (a == node.a) {
                if (b == node.b) {
                    return c < node.c;
                }
                return b < node.b;
            }
            return a < node.a;
        }
        bool operator !=(const Node &node) const {
            return a != node.a || b != node.b || c != node.c;
        }
        vector<int> toTriplet() {
            vector<int> ret;
            ret.push_back(a);
            ret.push_back(b);
            ret.push_back(c);
            return ret;
        }
    };
};
