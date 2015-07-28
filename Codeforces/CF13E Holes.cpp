#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m;
int power[MAXN];
int blockLen, blockNum;
int nextIndex[MAXN], nextCount[MAXN], nextLast[MAXN];

void update(int l, int r) {
    for (int i = r - 1; i >= l; --i) {
        int next = i + power[i];
        int blockIdx = i / blockLen;
        if (next >= (blockIdx + 1) * blockLen || next >= n) {
            nextIndex[i] = min(n, next);
            nextCount[i] = 1;
            nextLast[i] = i;
        } else {
            nextIndex[i] = nextIndex[next];
            nextCount[i] = nextCount[next] + 1;
            nextLast[i] = nextLast[next];
        }
    }
}

int main() {
    int op, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &power[i]);
    }
    blockLen = sqrt(MAXN);
    blockNum = (n + blockLen - 1) / blockLen;
    update(0, n);
    while (m--) {
        scanf("%d%d", &op, &a);
        --a;
        if (op == 0) {
            scanf("%d", &b);
            power[a] = b;
            int blockIdx = a / blockLen;
            update(blockIdx * blockLen, a + 1);
        } else {
            int num = 0;
            int last = a;
            while (a != n) {
                num += nextCount[a];
                last = nextLast[a];
                a = nextIndex[a];
            }
            printf("%d %d\n", last + 1, num);
        }
    }
    return 0;
}
