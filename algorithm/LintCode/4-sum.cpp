#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<Node> nodes;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int front = j + 1, rear = nums.size() - 1;
                while (front < rear) {
                    int temp = nums[i] + nums[j] + nums[front] + nums[rear];
                    if (temp == target) {
                        nodes.push_back({nums[i], nums[j], nums[front], nums[rear]});
                        ++front;
                        --rear;
                    } else if (temp < target) {
                        ++front;
                    } else {
                        --rear;
                    }
                }
            }
        }
        vector<vector<int> > ret;
        sort(nodes.begin(), nodes.end());
        for (int i = 0; i < nodes.size(); ++i) {
            if (i == 0) {
                ret.push_back(nodes[i].toVector());
            } else if (nodes[i] != nodes[i - 1]) {
                ret.push_back(nodes[i].toVector());
            }
        }
        return ret;
    }
private:
    struct Node {
        int a, b, c, d;
        bool operator <(const Node &node) const {
            if (a == node.a) {
                if (b == node.b) {
                    if (c == node.c) {
                        return d < node.d;
                    }
                    return c < node.c;
                }
                return b < node.b;
            }
            return a < node.a;
        }
        bool operator != (const Node &node) const {
            return a != node.a || b != node.b || c != node.c || d != node.d;
        }
        vector<int> toVector() {
            return {a, b, c, d};
        }
    };
};
