#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int n, a[MAXN][MAXN], b[MAXN][MAXN];
bool operator <(const vector<int> &a, const vector<int> &b) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            return true;
        }
        if (a[i] > b[i]) {
            return false;
        }
    }
    return false;
}

bool operator ==(const vector<int> &a, const vector<int> &b) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void pushTo(vector<int> &a, vector<int> &b) {
    int n = b.size();
    for (int i = 0; i < n; ++i) {
        a.push_back(b[i]);
    }
}

vector<int> combine(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d) {
    vector<int> r;
    pushTo(r, a);
    pushTo(r, b);
    pushTo(r, c);
    pushTo(r, d);
    return r;
}

int t1[MAXN][MAXN], t2[MAXN][MAXN];

vector<int> getRMin(int a[MAXN][MAXN], int l, int r, int u, int d, int k) {
    vector<int> mini;
    for (int i = l; i < r; ++i) {
        for (int j = u; j < d; ++j) {
            mini.push_back(a[i][j]);
        }
    }
    int n = r - l;
    for (int i = l; i < r; ++i) {
        for (int j = u; j < d; ++j) {
            t1[i - l][j - u] = a[i][j];
        }
    }
    for (int k = 0; k < 3; ++k) {
        vector<int> com;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t2[i][j] = t1[n - j - 1][i];
                com.push_back(t2[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t1[i][j] = t2[i][j];
            }
        }
        mini = min(mini, com);
    }
    return mini;
}

vector<int> getMini(int a[MAXN][MAXN], int l, int r, int u, int d) {
    if ((r - l) & 1) {
        return min(min(getRMin(a, l, r, u, d, 0),
                       getRMin(a, l, r, u, d, 1)),
                   min(getRMin(a, l, r, u, d, 2),
                       getRMin(a, l, r, u, d, 3)));
    }
    vector<int> mins[4];
    int midX = (l + r) >> 1;
    int midY = (u + d) >> 1;
    mins[0] = getMini(a, l, midX, u, midY);
    mins[1] = getMini(a, l, midX, midY, d);
    mins[2] = getMini(a, midX, r, midY, d);
    mins[3] = getMini(a, midX, r, u, midY);
    return min(min(combine(mins[0], mins[1], mins[2], mins[3]),
                   combine(mins[1], mins[2], mins[3], mins[0])),
               min(combine(mins[2], mins[3], mins[0], mins[1]),
                   combine(mins[3], mins[0], mins[1], mins[2])));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &b[i][j]);
            }
        }
        puts((getMini(a, 0, n, 0, n) == getMini(b, 0, n, 0, n)) ? "Yes" : "No");
    }
    return 0;
}
