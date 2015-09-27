#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
const int MAXV = 10000 + 10;

int n, l[MAXN], r[MAXN];

int main() {
    int minVal = MAXV, maxVal = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        minVal = min(minVal, l[i]);
        maxVal = max(maxVal, r[i]);
    }
    double ans = 0.0;
    for (int v = minVal; v <= maxVal; ++v) {
        double probUp = 0.0;
        double probEq = 0.0;
        for (int i = 0; i < n; ++i) {
            if (r[i] > v) {
                double tmp1 = (double)(r[i] - max(v, l[i] - 1)) / (r[i] - l[i] + 1);
                for (int j = 0; j < (1 << n); ++j) {
                    int cnt = 0;
                    double tmp2 = 1.0;
                    for (int k = 0; k < n; ++k) {
                        if (k != i) {
                            if (j & (1 << k)) {
                                if (l[k] <= v && v <= r[k]) {
                                    ++cnt;
                                    tmp2 *= 1.0 / (r[k] - l[k] + 1);
                                } else {
                                    tmp2 = 0.0;
                                    break;
                                }
                            } else {
                                if (v > l[k]) {
                                    tmp2 *= (double)(min(v, r[k] + 1) - l[k]) / (r[k] - l[k] + 1);
                                } else {
                                    tmp2 = 0.0;
                                    break;
                                }
                            }
                        }
                    }
                    if (cnt >= 1) {
                        probUp += tmp1 * tmp2;
                    }
                }
            }
        }
        probUp *= 0.5;
        for (int i = 0; i < (1 << n); ++i) {
            int cnt = 0;
            double tmp = 1.0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    if (l[j] <= v && v <= r[j]) {
                        ++cnt;
                        tmp *= 1.0 / (r[j] - l[j] + 1);
                    } else {
                        tmp = 0.0;
                        break;
                    }
                } else {
                    if (v > l[j]) {
                        tmp *= (double)(min(v, r[j] + 1) - l[j]) / (r[j] - l[j] + 1);
                    } else {
                        tmp = 0.0;
                    }
                }
            }
            if (cnt >= 2) {
                probEq += tmp;
            }
        }
        ans += (probUp + probEq) * v;
    }
    printf("%.10f\n", ans);
    return 0;
}
