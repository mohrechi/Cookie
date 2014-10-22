class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        int closest = 0;
        bool first = true;
        sort(nums.begin(), nums.end());
        for (int k = 2; k < nums.size(); ++k) {
            int front = 0, rear = k - 1;
            while (front != rear) {
                int temp = nums[front] + nums[rear] + nums[k];
                if (first || abs(temp - target) < abs(closest - target)) {
                    first = false;
                    closest = temp;
                }
                if (temp == target) {
                    break;
                } else if (temp < target) {
                    ++front;
                } else {
                    --rear;
                }
            }
        }
        return closest;
    }
};
