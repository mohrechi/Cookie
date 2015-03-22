class Solution {
public:
    struct Version {
        vector<int> nums;
        Version(string s) {
            int num = 0;
            for (int i = 0; i <= s.length(); ++i) {
                if (i == s.length() || s[i] == '.') {
                    nums.push_back(num);
                    num = 0;
                } else {
                    num = num * 10 + s[i] - '0';
                }
            }
        }
    };

    int compareVersion(string version1, string version2) {
        Version v1(version1);
        Version v2(version2);
        while (v1.nums.size() < v2.nums.size()) {
            v1.nums.push_back(0);
        }
        while (v1.nums.size() > v2.nums.size()) {
            v2.nums.push_back(0);
        }
        for (int i = 0; i < min(v1.nums.size(), v2.nums.size()); ++i) {
            if (v1.nums[i] < v2.nums[i]) {
                return -1;
            }
            if (v1.nums[i] > v2.nums[i]) {
                return 1;
            }
        }
        return 0;
    }
};
