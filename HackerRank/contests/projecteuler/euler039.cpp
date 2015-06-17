#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e6 + 1;

void calc() {
    int maxNum = 0;
    for (long long i = 12; i < MAXN; ++i) {
        int num = 0;
        for (long long a = 1; a < (i >> 1); ++a) {
            long long bu = i * i - 2 * i * a;
            long long bd = 2 * (i - a);
            if (bu % bd == 0) {
                long long b = bu / bd;
                if (a < b and b < i - a - b) {
                    ++num;
                }
            }
        }
        if (num > maxNum) {
            maxNum = num;
            cout << i << endl;
        }
    }
}

int main() {
    int T, N;
    int ans[] = {12, 60, 120, 240, 420, 720, 840, 1680, 2520, 4620, 5040, 9240,
                 18480, 27720, 55440, 110880, 120120, 166320, 180180, 240240,
                 360360, 720720, 1081080, 1441440, 2042040, 2162160, 2882880,
                 3603600, 4084080, MAXN};
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; ; ++i) {
            if (N < ans[i]) {
                cout << ans[i - 1] << endl;
                break;
            }
        }
    }
    return 0;
}
