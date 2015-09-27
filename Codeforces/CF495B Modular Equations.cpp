#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    while (cin >> a >> b) {
        if (a == b) {
            cout << "infinity" << endl;
        } else if (a < b) {
            cout << 0 << endl;
        } else {
            int cnt = 0;
            a = a - b;
            b = b == 0 ? -1 : b;
            for (long long i = 1; i * i <= a; ++i) {
                if (a % i == 0) {
                    long long j = a / i;
                    if (i == j) {
                        j = -1;
                    }
                    cnt += i > b;
                    cnt += j > b;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
