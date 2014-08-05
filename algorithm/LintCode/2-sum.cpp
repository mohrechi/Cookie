#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> origin = nums;
        sort(nums.begin(), nums.end());
        int index1 = 0, index2 = nums.size() - 1;
        while (true) {
            int temp = nums[index1] + nums[index2];
            if (temp == target) {
                break;
            } else if (temp < target) {
                ++index1;
            } else {
                --index2;
            }
        }
        vector<int> result;
        for (int i = 0; i < origin.size(); ++i) {
            if (origin[i] == nums[index1]) {
                result.push_back(i + 1);
            } else if (origin[i] == nums[index2]) {
                result.push_back(i + 1);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

