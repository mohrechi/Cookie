#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Exam {
    int a, b;
    bool operator <(const Exam &exam) const {
        return b < exam.b;
    }
} exam[MAXN];

int main() {
    long long n, r, avg;
    ios::sync_with_stdio(false);
    while (cin >> n >> r >> avg) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> exam[i].a >> exam[i].b;
            sum += exam[i].a;
        }
        sort(exam, exam + n);
        long long rem = n * avg - sum;
        long long ans = 0;
        for (int i = 0; i < n && rem > 0; ++i) {
            if (rem > r - exam[i].a) {
                rem -= r - exam[i].a;
                ans += (r - exam[i].a) * exam[i].b;
            } else {
                ans += rem * exam[i].b;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
