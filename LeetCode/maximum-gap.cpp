class Solution {
public:
    class Interval {
    public:
        bool isEmpty;
        int minVal, maxVal;
        Interval() {
            isEmpty = true;
            minVal = INT_MAX;
            maxVal = INT_MIN;
        }
        void addVal(int val) {
            isEmpty = false;
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
        }
    };

    int maximumGap(vector<int> &num) {
        if (num.size() < 2) {
            return 0;
        }
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (auto val : num) {
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
        }
        int maxGap = (maxVal - minVal + num.size() - 2) / (num.size() - 1);
        int intervalNum = (maxVal - minVal + 1 + maxGap) / (maxGap + 1);
        vector<Interval> intervals;
        for (int i = 0; i < intervalNum; ++i) {
            intervals.push_back(Interval());
        }
        for (auto val : num) {
            int index = (val - minVal) / (maxGap + 1);
            intervals[index].addVal(val);
        }
        for (int i = 0; i < intervalNum; ++i) {
            if (intervals[i].isEmpty) {
                continue;
            } else {
                for (int j = i + 1; j < intervalNum; ++j) {
                    if (intervals[j].isEmpty) {
                        continue;
                    } else {
                        maxGap = max(maxGap, intervals[j].minVal - intervals[i].maxVal);
                        i = j - 1;
                        break;
                    }
                }
            }
        }
        return maxGap;
    }
};
