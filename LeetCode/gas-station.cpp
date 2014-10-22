class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int sum = 0;
        int last = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                last = i + 1;
                sum = 0;
            }
        }
        return total >= 0 ? last : -1;
    }
};
