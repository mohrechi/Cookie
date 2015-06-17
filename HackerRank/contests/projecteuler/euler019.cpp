#include <bits/stdc++.h>
using namespace std;
const int DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool isLeapYear(long long y) {
    return y % 400 == 0 or (y % 100 and y % 4 == 0);
}

struct Date {
    long long y, m, d;
    long long delta;

    void calcDelta() {
        delta = (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
        for (int i = 1; i < m; ++i) {
            if (i == 2 and isLeapYear(y)) {
                delta += 29;
            } else {
                delta += DAYS[i];
            }
        }
        delta += d;
        delta %= 7;
    }

    void incMonth() {
        if (m == 2 and isLeapYear(y)) {
            delta += 29;
            m = 3;
        } else {
            delta += DAYS[m];
            if (++m > 12) {
                m = 1;
                ++y;
            }
        }
    }
};


istream& operator >>(istream& in, Date& date) {
    in >> date.y >> date.m >> date.d;
    return in;
}

ostream& operator <<(ostream& out, const Date& date) {
    out << date.y << ' ' << date.m << ' ' << date.d;
    return out;
}

bool operator <=(const Date& a, const Date& b) {
    if (a.y < b.y) return true;
    if (a.y > b.y) return false;
    if (a.m < b.m) return true;
    if (a.m > b.m) return false;
    return a.d <= b.d;
}

inline int zeller(int y, int m, int d) {
    if (m == 1 or m == 2) {
        m += 12;
        --y;
    }
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

int main() {
    int T;
    Date start, a, b;
    start = {1900, 1, 1};
    start.calcDelta();
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int ans = 0;
        if (a.d != 1) {
            a.d = 1;
            a.incMonth();
        }
        a.calcDelta();
        a.delta = (a.delta - start.delta + 7) % 7;
        while (a <= b) {
            if (a.delta % 7 == 6) {
                ++ans;
            }
            a.incMonth();
        }
        cout << ans << endl;
    }
    return 0;
}
