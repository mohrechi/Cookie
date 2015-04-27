#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int n;
long long m;
long long a[MAXN];
long long sum[MAXN];
long long dp[MAXN];
int bound[MAXN];
int que[MAXN];
multiset<long long> choices;

int main() {
    while (~scanf("%d%lld", &n, &m)) {
        bool invalid = false;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            if (a[i] > m) {
                invalid = true;
            }
        }
        if (invalid) {
            puts("-1");
            continue;
        }
        int front = 0, rear = 0, left = 0;
        choices.clear();
        for (int i = 1; i <= n; ++i) {
            while (sum[i] - sum[left] > m) {
                ++left;
            }
            while (front < rear && que[front] <= left) {
                choices.erase(choices.find(dp[bound[front]] + a[que[front]]));
                ++front;
            }
            while (front < rear && a[i] >= a[que[rear - 1]]) {
                choices.erase(choices.find(dp[bound[rear - 1]] + a[que[rear - 1]]));
                --rear;
            }
            if (front < rear && left != bound[front]) {
                choices.erase(choices.find(dp[bound[front]] + a[que[front]]));
                bound[front] = left;
                choices.insert(dp[bound[front]] + a[que[front]]);
            }
            if (front < rear) {
                bound[rear] = que[rear - 1];
            } else {
                bound[rear] = left;
            }
            choices.insert(dp[bound[rear]] + a[i]);
            que[rear++] = i;
            dp[i] = *choices.begin();
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
