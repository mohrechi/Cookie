#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, n, X;
    while (cin >> A >> B >> n) {
        bool hasSolution = true;
        if (B == 0) {
            X = 0;
        } else if (A == 0 or abs(B / A) < 1 or B % A) {
            hasSolution = false;
        } else {
            int C = B / A;
            if (C < 0 and n % 2 == 0) {
                hasSolution = false;
            } else {
                if (n == 1) {
                    X = C;
                } else {
                    int l = 1, r = 32;
                    hasSolution = false;
                    while (l <= r) {
                        int mid = (l + r) >> 1;
                        long long val = 1;
                        for (int i = 0; i < n; ++i) {
                            val *= mid;
                        }
                        if (val == abs(C)) {
                            hasSolution = true;
                            if (C < 0) {
                                X = -mid;
                            } else {
                                X = mid;
                            }
                            break;
                        } else if (val < abs(C)) {
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                }
            }
        }
        if (hasSolution) {
            cout << X << endl;
        } else {
            cout << "No solution" << endl;
        }
    }
    return 0;
}
