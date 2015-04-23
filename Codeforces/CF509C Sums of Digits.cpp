#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 10;

int main() {
    int n, a[MAXN], b[MAXN], len;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        len = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                int t = b[i];
                while (t) {
                    if (t >= 9) {
                        a[len++] = 9;
                        t -= 9;
                    } else {
                        a[len++] = t;
                        break;
                    }
                }
            } else {
                int t = b[i] - b[i - 1];
                if (t <= 0) {
                    int sum = a[0];
                    for (int i = 1; i <= len; ++i) {
                        if (i == len) {
                            a[len++] = 1;
                            for (int j = 0; j < i; ++j) {
                                a[j] = 0;
                            }
                            break;
                        }
                        if (a[i] < 9) {
                            if (sum - 1 >= abs(t)) {
                                ++a[i];
                                for (int j = 0; j < i; ++j) {
                                    a[j] = 0;
                                }
                                break;
                            }
                        }
                        sum += a[i];
                    }
                }
                int sum = 0;
                for (int i = 0; i < len; ++i) {
                    sum += a[i];
                }
                t = b[i] - sum;
                for (int i = 0; i <= len && t; ++i) {
                    if (i == len) {
                        a[len++] = 1;
                        --t;
                        --i;
                    } else if (a[i] < 9) {
                        ++a[i];
                        --t;
                        --i;
                    }
                }
            }
            for (int i = len - 1; i >= 0; --i) {
                cout << a[i];
            }
            cout << endl;
        }
    }
    return 0;
}
