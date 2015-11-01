#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 5;

int n, a[MAXN], b[MAXN], posA[MAXN], posB[MAXN];

void readPerm(int n, int a[], int pos[]) {
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
}

int main() {
    scanf("%d", &n);
    readPerm(n, b, posB);
    readPerm(n, a, posA);
    int cost = 0;
    vector<pair<int, int>> moves;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[i]) {
            int j = posB[a[i]];
            for (int k = j - 1; k >= i; --k) {
                if (k < j) {
                    if (posA[b[k]] >= j) {
                        cost += j - k;
                        moves.push_back({j, k});
                        swap(b[j], b[k]);
                        swap(posB[b[j]], posB[b[k]]);
                        j = k;
                    }
                }
            }
        }
    }
    printf("%d\n", cost);
    printf("%d\n", (int)moves.size());
    for (auto m : moves) {
        printf("%d %d\n", m.first, m.second);
    }
    return 0;
}
