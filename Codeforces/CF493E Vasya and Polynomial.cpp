#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, a, b;
    while (cin >> t >> a >> b) {
        if (t == a) {
            if (a == b) {
                if (t == 1) {
                    puts("inf");
                } else {
                    puts("2");
                }
            } else {
                puts("0");
            }
        } else if (a == b) {
            puts("1");
        } else if (t > a || a > b) {
            puts("0");
        } else {
            long long c = 0, d = 1;
            while (b) {
                c += (b % a) * d;
                b /= a;
                d *= t;
            }
            if (t == 1) {
                if (c == a || c == 1) {
                    puts("1");
                } else {
                    puts("0");
                }
            } else {
                if (c == a) {
                    puts("1");
                } else {
                    puts("0");
                }
            }
        }
    }
    return 0;
}
