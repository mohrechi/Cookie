#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;

long long fact[MAXN];
bool visit[26];

string gen(long long rem, int d) {
    if (d < 0) {
        return "";
    }
    int pos = rem / fact[d], cnt = 0;
    long long next = rem - fact[d] * pos;
    for (int i = 0; i < 26; ++i) {
        if (!visit[i]) {
            if (cnt++ == pos) {
                visit[i] = true;
                pos = i;
                break;
            }
        }
    }
    return (char)(pos + 'a') + gen(next, d - 1);
}

int main() {
    int T;
    long long N;
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    cin >> T;
    while (T--) {
        cin >> N;
        memset(visit, false, sizeof(visit));
        cout << gen(N - 1, 12) << endl;
    }
    return 0;
}
