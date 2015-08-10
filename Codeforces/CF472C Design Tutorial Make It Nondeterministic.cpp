#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXL = 50 + 10;

int n;
string f[MAXN], l[MAXN];

int main() {
    int p;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i] >> l[i];
    }
    bool possible = true;
    string last;
    for (int i = 1; i <= n; ++i) {
        possible = false;
        cin >> p;
        if (f[p] > last) {
            possible = true;
            if (l[p] < f[p] && l[p] > last) {
                last = l[p];
            } else {
                last = f[p];
            }
        } else if (l[p] > last) {
            possible = true;
            last = l[p];
        }
        if (!possible) {
            break;
        }
    }
    puts(possible ? "YES" : "NO");
    return 0;
}
