#include <bits/stdc++.h>
using namespace std;

int main() {
    int r1, r2;
    int c1, c2;
    int d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int a = (r1 + d1 - c2) / 2;
    int b = (r1 - d1 + c2) / 2;
    int c = (r2 + d2 - c2) / 2;
    int d = (r2 - d2 + c2) / 2;
    if (a + b == r1 and c + d == r2) {
        if (a + c == c1 and b + d == c2) {
            if (a + d == d1 and b + c == d2) {
                if (1 <= a and a <= 9) {
                    if (1 <= b and b <= 9) {
                        if (1 <= c and c <= 9) {
                            if (1 <= d and d <= 9) {
                                if (a != b and a != c and a != d) {
                                    if (b != c and b != d) {
                                        if (c != d) {
                                            cout << a << " " << b << endl;
                                            cout << c << " " << d << endl;
                                            exit(0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
