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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.size() == 0) {
            return {newInterval};
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<Interval> ret;
        int start = intervals[0].start, end = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > end) {
                ret.push_back({start, end});
                start = intervals[i].start;
                end = intervals[i].end;
            } else {
                end = max(end, intervals[i].end);
            }
        }
        ret.push_back({start, end});
        return ret;
    }
};
