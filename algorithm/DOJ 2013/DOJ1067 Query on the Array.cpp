#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500005;
const int MAXM = 1000005;
const int SHIFT = 500001;

class TreeArray {
public:
    int n;
    void clear() {
        for (int i = 0; i <= n; ++i) {
            c[i] = 0;
        }
    }
    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }
    long long query(int x) {
        long long sum = 0;
        while (x > 0) {
            sum += c[x];
            x -= lowbit(x);
        }
        return sum;
    }
    long long query(int x, int y) {
        if (x > y) {
            swap(x, y);
        }
        return query(y) - query(x - 1);
    }
    inline int findKth(int k) {
        int count = 0, index = 0;
        for (int i = 20; i >= 0; --i) {
            index += 1 << i;
            if (index > n || count + c[index] >= k) {
                index -= 1 << i;
            } else {
                count += c[index];
            }
        }
        return index + 1;
    }
private:
    long long c[MAXM];
    inline int lowbit(int x) {
        return x & (-x);
    }
} arraySort, arraySum;

int n, m;
int a[MAXN];

int main() {
    int x, y;
    char s[10];
    while (~scanf("%d%d", &n, &m)) {
        arraySort.n = MAXM - 1;
        arraySum.n = n;
        arraySort.clear();
        arraySum.clear();
        map<int, int> index;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            arraySort.update(a[i] + SHIFT, 1);
            arraySum.update(i, a[i]);
            index[a[i]] = i;
        }
        while (m--) {
            scanf("%s%d%d", s, &x, &y);
            if (s[0] == 'C') {
                int k = arraySort.findKth(x);
                arraySort.update(k, -1);
                arraySort.update(y + SHIFT, 1);
                arraySum.update(index[k - SHIFT], y - (k - SHIFT));
                index[y] = index[k - SHIFT];
            } else {
                printf("%lld\n", arraySum.query(x, y));
            }
        }
    }
    return 0;
}
