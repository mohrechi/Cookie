#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n;
int prices[MAXN];
int leftPrices[MAXN];
int rightPrices[MAXN];

int methodN() {
    if (n <= 1) {
        return 0;
    }
    int ans = 0;
    int minPrice = prices[0];
    leftPrices[0] = 0;
    for (int i = 1; i < n; ++i) {
        leftPrices[i] = max(leftPrices[i - 1], prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    int maxPrice = prices[n - 1];
    rightPrices[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        rightPrices[i] = max(rightPrices[i + 1], maxPrice - prices[i]);
        maxPrice = max(maxPrice, prices[i]);
    }
    for (int i = 0; i < n; ++i) {
        ans = max(ans, leftPrices[i] + rightPrices[i]);
    }
    return ans;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &prices[i]);
        }
        printf("%d\n", methodN());
    }
    return 0;
}
