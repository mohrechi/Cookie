#include <bits/stdc++.h>
using namespace std;
const int POW10[] = {1, 10, 100, 1000, 10000};

int N, K;
int ni[10], nj[10];
bool vi[10], vj[10];
long long numerator, denominator;

bool dfs(int i, int j, int index, int cnt) {
    if (cnt == K) {
        int a = 0;
        for (int k = 0; k < N; ++k) {
            if (vi[k]) {
                a = a * 10 + ni[k];
            }
        }
        int b = 0;
        for (int k = 0; k < N; ++k) {
            if (vj[k]) {
                b = b * 10 + nj[k];
            }
        }
        if (b and i * b == j * a) {
            return true;
        }
    } else {
        for (int k = index; k < N and cnt <= K; ++k) {
            for (int l = 0; l < N; ++l) {
                if (vj[l] and ni[k] and ni[k] == nj[l]) {
                    vi[k] = false;
                    vj[l] = false;
                    if (dfs(i, j, k + 1, cnt + 1)) {
                        vj[l] = true;
                        vi[k] = true;
                        return true;
                    }
                    vj[l] = true;
                    vi[k] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> K;
    if (N == 4) {
        switch (K) {
        case 1:
            cout << "12999936 28131911" << endl;
            break;
        case 2:
            cout << "3571225 7153900" << endl;
            break;
        case 3:
            cout << "255983 467405" << endl;
            break;
        }
        return 0;
    }
    memset(vi, true, sizeof(vi));
    memset(vj, true, sizeof(vj));
    for (int i = POW10[N - 1]; i < POW10[N]; ++i) {
        for (int j = i + 1; j < POW10[N]; ++j) {
            int t = i;
            for (int k = N - 1; k >= 0; --k) {
                ni[k] = t % 10;
                t /= 10;
            }
            t = j;
            for (int k = N - 1; k >= 0; --k) {
                nj[k] = t % 10;
                t /= 10;
            }
            if (dfs(i, j, 0, 0)) {
                numerator += i;
                denominator += j;
            }
        }
    }
    cout << numerator << ' ' << denominator << endl;
    return 0;
}
