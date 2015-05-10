#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, A, B;
    cin >> T;
    while (T--) {
        cin >> A >> B;
        while (true) {
            long long G = __gcd(A, B);
            if (G == 1) {
                break;
            }
            B /= G;
        }
        cout << (B == 1 ? "Yes" : "No") << endl;
    }
    return 0;
}
