#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, m;
int a[MAXN], b[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + m);
    a[n] = b[m] = 2.1e9;
    int bestScoreA = n * 3, bestScoreB = m * 3;
    for (int i = 0, j = 0; i < n || j < m;) {
        if (a[i] < b[j]) {
            ++i;
        } else if (a[i] > b[j]) {
            ++j;
        } else {
            ++i, ++j;
        }
        int scoreA = i * 2 + (n - i) * 3;
        int scoreB = j * 2 + (m - j) * 3;
        if (scoreA - scoreB > bestScoreA - bestScoreB ||
            (scoreA - scoreB > bestScoreA - bestScoreB &&
             scoreA > bestScoreA)) {
            bestScoreA = scoreA;
            bestScoreB = scoreB;
         }
    }
    printf("%d:%d\n", bestScoreA, bestScoreB);
    return 0;
}
