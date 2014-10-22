/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator <(const Interval &a, const Interval &b) {
    if (a.start == b.start) {
        return a.end > b.end;
    }
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        sort(intervals.begin(), intervals.end());
        if (intervals.size() > 0) {
            int left = intervals[0].start;
            int right = intervals[0].end;
            for (int i = 1; i < intervals.size(); ++i) {
                if (intervals[i].start <= right) {
                    right = max(right, intervals[i].end);
                } else {
                    result.push_back({left, right});
                    left = intervals[i].start;
                    right = intervals[i].end;
                }
            }
            result.push_back({left, right});
        }
        return result;
    }
};
