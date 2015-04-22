#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, k;

struct Number {
    int value;
    bool unknown;
    friend istream& operator >>(istream& in, Number& num) {
        string s;
        in >> s;
        if (s[0] == '?') {
            num.unknown = true;
        } else {
            num.unknown = false;
            stringstream ss(s);
            ss >> num.value;
        }
        return in;
    }
    friend ostream& operator <<(ostream& out, Number& num) {
        out << num.value;
        return out;
    }
} num[MAXN];

bool tryFill(int left, int right) {
    long long lower = -INF, upper = INF;
    if (left - k >= 0) {
        lower = num[left - k].value;
    }
    if (right + k < n) {
        upper = num[right + k].value;
    }
    int cnt = (right - left) / k + 1;
    if (upper - lower - 1 < cnt) {
        return false;
    }
    set<int> numSet;
    if (lower <= 0 && upper >= 0) {
        if (lower != 0 && upper != 0) {
            numSet.insert(0);
        }
        int index = 1;
        while ((int)numSet.size() < cnt) {
            if (index < -lower) {
                numSet.insert(-index);
            }
            if (index < upper) {
                numSet.insert(index);
            }
            ++index;
        }
    } else if (upper < 0) {
        while ((int)numSet.size() < cnt) {
            numSet.insert(--upper);
        }
    } else {
        while ((int)numSet.size() < cnt) {
            numSet.insert(++lower);
        }
    }
    auto it = numSet.begin();
    for (int i = left; i <= right; i += k) {
        num[i].value = *(it++);
    }
    return true;
}

int main() {
    while (cin >> n >> k) {
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        bool valid = true;
        for (int i = 0, j; i < k && valid; ++i) {
            int left = -1, right;
            for (j = i; j < n && valid; j += k) {
                if (num[j].unknown && left == -1) {
                    left = j;
                }
                if (left != -1 && !num[j].unknown) {
                    right = j - k;
                    if (!tryFill(left, right)) {
                        valid = false;
                    }
                    left = -1;
                }
            }
            if (left != -1) {
                right = j - k;
                if (!tryFill(left, right)) {
                    valid = false;
                }
            }
        }
        for (int i = 0; i < n - k; ++i) {
            if (num[i].value >= num[i + k].value) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "Incorrect sequence" << endl;
        } else {
            for (int i = 0; i < n; ++i) {
                if (i) {
                    cout << ' ';
                }
                cout << num[i];
            }
            cout << endl;
        }
    }
    return 0;
}
