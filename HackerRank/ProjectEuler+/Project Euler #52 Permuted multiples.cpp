#include <bits/stdc++.h>
using namespace std;

long long dhash(int x) {
    int digit[10];
    memset(digit, 0, sizeof(digit));
    while (x) {
        ++digit[x % 10];
        x /= 10;
    }
    long long h = 1;
    for (int i = 0; i < 10; ++i) {
        h = h * 10 + digit[i];
    }
    return h;
}

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        long long first = dhash(i);
        bool valid = true;
        for (int j = 2; j <= K; ++j) {
            if (dhash(i * j) != first) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << i;
            for (int j = 2; j <= K; ++j) {
                cout << ' ' << i * j;
            }
            cout << endl;
        }
    }
    return 0;
}
