#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m;
int a[MAXN], b[MAXN];
long long fillA[MAXN], removeB[MAXN];

long long calcFill(int div) {
    if (a[0] >= div) {
        return 0;
    }
    int idx = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] < div) {
            l = mid + 1;
            idx = max(idx, mid);
        } else {
            r = mid - 1;
        }
    }
    return fillA[idx] + (long long)(div - a[idx]) * (idx + 1);
}

long long calcRemove(int div) {
    if (b[m - 1] <= div) {
        return 0;
    }
    int idx = m - 1;
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (b[mid] > div) {
            r = mid - 1;
            idx = min(idx, mid);
        } else {
            l = mid + 1;
        }
    }
    return removeB[idx] + (long long)(b[idx] - div) * (m - idx);
}

long long calcNum(long long div) {
    return calcFill(div) + calcRemove(div);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + m);
    if (a[0] > b[m - 1]) {
        puts("0");
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        fillA[i] = fillA[i - 1] + (long long)(a[i] - a[i - 1]) * i;
    }
    for (int i = m - 2; i >= 0; --i) {
        removeB[i] = removeB[i + 1] + (long long)(b[i + 1] - b[i]) * (m - i - 1);
    }
    int l = a[0], r = b[m - 1] + 1;
    long long ans = -1;
    while (l <= r) {
        int ll = l + (r - l) / 3;
        int rr = r - (r - l) / 3;
        long long numL = calcNum(ll);
        long long numR = calcNum(rr);
        if (numL > numR) {
            l = ll + 1;
            if (ans == -1 || ans > numR) {
                ans = numR;
            }
        } else {
            r = rr - 1;
            if (ans == -1 || ans > numL) {
                ans = numL;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
