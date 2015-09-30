#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << ((N * (N - 1)) >> 1) << endl;
    }
    return 0;
}
