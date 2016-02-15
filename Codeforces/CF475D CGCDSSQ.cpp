#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);
    vector<map<int, long long>> nums(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++nums[i][a];
        if (i) {
            for (auto num : nums[i - 1]) {
                nums[i][__gcd(num.first, a)] += num.second;
            }
        }
    }
    map<int, long long> total;
    for (int i = 0; i < n; ++i) {
        for (auto num : nums[i]) {
            total[num.first] += num.second;
        }
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        printf("%I64d\n", total[a]);
    }
    return 0;
}
