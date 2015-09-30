#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, N, Ni;
    cin >> T;
    while (T--) {
        cin >> N;
        long long ans = 1;
        while (--N) {
            cin >> Ni;
            ans = ans * Ni % 1234567;
        }
        cout << ans << endl;
    }
    return 0;
}
