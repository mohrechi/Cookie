/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool operator ==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

Point operator -(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

Point center;

long long operator ^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

long long cross(const Point &a, const Point &b) {
    return (a - center) ^ (b - center);
}


bool operator <(const Point &a, const Point &b) {
    return cross(a, b) > 0;
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int ans = min(2, (int)points.size());
        for (int i = 0; i < points.size(); ++i) {
            center = points[i];
            vector<Point> tempPoints;
            int same = 0;
            for (int j = 0; j < points.size(); ++j) {
                if (j != i) {
                    if (points[j] == center) {
                        ++same;
                    } else {
                        tempPoints.push_back(points[j]);
                    }
                }
            }
            ans = max(ans, same + 1);
            sort(tempPoints.begin(), tempPoints.end());
            int list = 2;
            for (int j = 1; j < tempPoints.size(); ++j) {
                if (cross(tempPoints[j], tempPoints[j - 1]) == 0) {
                    if (++list + same >= ans) {
                        ans = list + same;
                    }
                } else {
                    list = 2;
                }
            }
        }
        return ans;
    }
};
