#include <bits/stdc++.h>
using namespace std;

long long l, r, k;
long long ans, ansNum, path[6], record[6];

void dfs(long long x, int num, long long sum) {
    if (num > 0) {
        if (sum < ans) {
            ans = sum;
            ansNum = num;
            for (int i = 0; i < num; ++i) {
                record[i] = path[i];
            }
        }
    }
    if (num == k or x > r) {
        return;
    }
    dfs(x + 1, num, sum);
    path[num] = x;
    dfs(x + 1, num + 1, sum ^ x);
}

int main() {
    cin >> l >> r >> k;
    if (r - l > 6) {
        if (k == 1) {
            cout << l << endl;
            cout << 1 << endl;
            cout << l << endl;
        } else if (k == 2) {
            cout << 1 << endl;
            cout << 2 << endl;
            if (l & 1) ++l;
            cout << l << " " << l + 1 << endl;
        } else if (k == 3) {
            long long a = 1, b = 2, c = 3;
            bool found = false;
            while (c <= r) {
                if (a >= l) {
                    found = true;
                    break;
                }
                (a <<= 1) |= 1;
                (b <<= 1) |= 1;
                c <<= 1;
            }
            if (found) {
                cout << 0 << endl;
                cout << 3 << endl;
                cout << a << " " << b << " " << c << endl;
            } else {
                cout << 1 << endl;
                cout << 2 << endl;
                if (l & 1) ++l;
                cout << l << " " << l + 1 << endl;
            }
        } else {
            cout << 0 << endl;
            cout << 4 << endl;
            while (l & 3) ++l;
            for (int i = 0; i < 4; ++i) cout << l + i << " ";
            cout << endl;
        }
    } else {
        ans = r + 1;
        dfs(l, 0, 0);
        cout << ans << endl;
        cout << ansNum << endl;
        for (int i = 0; i < ansNum; ++i) cout << record[i] << " ";
        cout << endl;
    }
    return 0;
}
